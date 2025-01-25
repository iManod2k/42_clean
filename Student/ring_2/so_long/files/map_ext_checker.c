#include "../include/so_long.h"

static int	check_ext(char *map)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_end, ext, ft_strlen(name_end)) != 0)
	{
		free(name_end);
		return (0);
	}
	free(name_end);
	return (1);
}

t_game	*valid_map(char *map_name, t_game *game)
{
	if (!check_ext(map_name))
	{
		ft_nomap(game, "Please provide a map with a valid extension");
		return (0);
	}
	if (!map_init(map_name, game))
	{
		ft_nomap(game, "Please provide a map.");
		return (0);
	}
	if (!check_map(game))
		return (0);
	if (!flood_it(game))
		return (0);

	if (game->map.map)
		map_destroyer(game);
	map_init(map_name, game);
	return (game);
}
