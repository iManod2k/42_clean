/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_general_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:32:19 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/25 22:55:27 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_character(char iji, t_game *game)
{
	char	*char_ok;

	char_ok = "01EPC";
	if (iji == 'P')
		game->map.hero_count++;
	if (iji == 'E')
		game->map.exit_count++;
	if (iji == 'C')
		game->map.item_count++;
	if (!ft_strchr(char_ok, iji))
	{
		ft_error(game, "Detected invalid character on Map.");
		return (0);
	}
	if (game->map.hero_count > 1 || game->map.exit_count > 1)
	{
		if (game->map.hero_count > 1)
			ft_error(game, "Only 1 player allowed");
		else if (game->map.exit_count > 1)
			ft_error(game, "Only 1 exit allowed");
		return (0);
	}
	return (1);
}

static int	valid_character(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (!check_character(game->map.map[i][j], game))
				return (0);
			j++;
		}
		i++;
	}
	if (!is_mission_ready(game))
		return (0);
	return (1);
}

static int	closed_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.col_size && j < game->map.line_size)
	{
		while (j < game->map.line_size)
		{
			if (game->map.map[i][0] != '1' ||
				game->map.map[i][game->map.line_size - 1] != '1' ||
				game->map.map[0][j] != '1' ||
				game->map.map[game->map.col_size - 1][j] != '1')
				{
					ft_printf("%d - %d\n", i, j);
					return (0);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	shape(t_game *game)
{
	int	i;
	int	check;

	i = 0;
	check = game->map.line_size;
	while (++i < game->map.col_size - 1)
	{
		if (game->map.map[i][0] == '\n')
			return (0);
		if (!(game->map.map[i][check - 1] && game->map.map[i][check] == '\n'))
			return (0);
	}
	if (game->map.map[i][check] != 0)
	{
		if (game->map.map[i][check] == 'n' && game->map.map[i][check + 1] != 0)
			return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!shape(game))
	{
		ft_error(game, "Please provide a rectangular map");
		return (0);
	}
	if (!closed_up(game))
	{
		ft_error(game, "Please provide a closed map");
		return (0);
	}
	if (!valid_character(game))
		return (0);
	return (1);
}
