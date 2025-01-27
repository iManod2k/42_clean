/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_reachable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:29 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:48 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flooder(t_game *game, t_map size, t_character charpos, char filler)
{
	if ((charpos.y_char < 0 || charpos.y_char >= size.y_map || \
		charpos.x_char < 0 || charpos.x_char >= size.x_map) || \
		((game->map.map[charpos.y_char][charpos.x_char] != filler && \
		game->map.map[charpos.y_char][charpos.x_char] != 'C' && \
		game->map.map[charpos.y_char][charpos.x_char] != 'E')))
		return ;
	if (game->map.map[charpos.y_char][charpos.x_char] == 'C' || \
		game->map.map[charpos.y_char][charpos.x_char] == 'E')
	{
		if (game->map.map[charpos.y_char][charpos.x_char] == 'C')
			game->map.item_count++;
		if (game->map.map[charpos.y_char][charpos.x_char] == 'E')
			game->map.exit_count++;
		game->map.map[charpos.y_char][charpos.x_char] = filler;
	}
	game->map.map[charpos.y_char][charpos.x_char] = 'F';
	flooder(game, size, (t_character){.x_char = charpos.x_char - 1, \
		.y_char = charpos.y_char}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char + 1, \
		.y_char = charpos.y_char}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char, \
		.y_char = charpos.y_char - 1}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char, \
		.y_char = charpos.y_char + 1}, filler);
}

static void	flood_caller(t_game *game, t_map size, t_character charpos)
{
	if (game->map.map[charpos.y_char][charpos.x_char] == 'P')
		game->map.map[charpos.y_char][charpos.x_char] = '0';
	if (game->map.map[charpos.y_char][charpos.x_char] == 'C')
		game->map.map[charpos.y_char][charpos.x_char] = '0';
	flooder(game, size, charpos, game->map.map[charpos.y_char][charpos.x_char]);
}

static int	caught_em_all(t_game *game, int itemy, int exity)
{
	if (itemy != game->map.item_count)
	{
		ft_error(game, "Items ẃeren't collected");
		return (0);
	}
	if (exity != game->map.exit_count)
	{
		ft_error(game, "No exit found !");
		return (0);
	}
	return (1);
}

int	flood_it(t_game *game)
{
	t_character	charpos;
	t_map		size;
	int			itemy;
	int			exity;

	itemy = game->map.item_count;
	exity = game->map.exit_count;
	game->map.item_count = 0;
	game->map.exit_count = 0;
	charpos = (t_character){.x_char = game->player.x_char, \
		.y_char = game->player.y_char};
	size = (t_map){.x_map = game->map.line_size, .y_map = game->map.col_size};
	flood_caller(game, size, charpos);
	if (!caught_em_all(game, itemy, exity))
		return (0);
	return (1);
}
