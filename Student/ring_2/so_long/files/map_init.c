/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:17:23 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/24 20:04:57 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	update_size(t_game *game, int x, int y)
{
	game->map.line_size = x - 1;
	game->map.col_size = y - 1;
}

static void	get_coord(char *map_name, t_game *game)
{
	char	*mapper;
	int		i;
	int		fd;
	int		j;

	i = 0;
	j = 0;
	mapper = "";
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		return ;
	else
	{
		while (map_name != NULL && mapper != NULL && ++j)
		{
			mapper = get_next_line(fd);
			if (mapper && !i)
				i = ft_strlen(mapper);
			free(mapper);
		}
	}
	update_size(game, i, j);
	close(fd);
}

static char	**fill_map(char *map_name, t_game *game, char **mapping)
{
	int		i;
	int		fd;
	char	*liner;

	i = 0;
	liner = "";
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		return (0);
	else
	{
		while (map_name != NULL && liner != NULL)
		{
			while (i <= game->map.col_size)
			{
				liner = get_next_line(fd);
				if (liner)
					mapping[i] = ft_strdup(liner);
				free(liner);
				i++;
			}
		}
	}
	close(fd);
	return (mapping);
}

t_game	*map_init(char *map_name, t_game *game)
{
	get_coord(map_name, game);
	if (game->map.line_size >= 3 && game->map.col_size >= 3)
	{
		game->map.map = malloc(sizeof(char) * (game->map.line_size + 1) * (game->map.col_size + 1) + 1);
		if (!game->map.map)
			return (0);
		else
			game->map.map = fill_map(map_name, game, game->map.map);
	}
	else
		return (0);
	return (game);
}