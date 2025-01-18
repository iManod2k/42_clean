/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:57:32 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 16:58:57 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_pos(int i, int j, t_game *game)
{
	game->player.x_char = j;
	game->player.y_char = i;
}

static void	exit_pos(int i, int j, t_game *game)
{
	game->exit.x_tile = j;
	game->exit.y_tile = i;
}

static t_game	*set_elem_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] == 'P')
				player_pos(i, j, game);
			if (game->map.map[i][j] == 'E')
				exit_pos(i, j, game);
			j++;
		}
		i++;
	}
	return (game);
}

int	is_mission_ready(t_game *game)
{
	if (game->map.hero_count == 0)
	{
		ft_error(game, "Can't start mission!\n\tNobody volunteered");
		return (0);
	}
	if (game->map.exit_count == 0)
	{
		ft_error(game, "Can't start mission!\n\tThere's no way out");
		return (0);
	}
	if (game->map.item_count == 0)
	{
		ft_error(game, "Can't start mission!\n\tNo quest available");
		return (0);
	}
	game = set_elem_pos(game);
	return (1);
}
