/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:38:50 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:38:51 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "keys.h"
# include "../mlx/mlx_int.h"
# include "../mlx/mlx.h"
# include <stdint.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 480
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 640
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

// Casilla
typedef struct s_tile
{
	int				x_tile;
	int				y_tile;
	char			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_tile;

// Personaje
typedef struct s_character
{
	int				x_char;
	int				y_char;
	char			*charac;
	int				move_count;
	int				inventory;
}	t_character;

// Mapa
typedef struct s_map
{
	int				x_map;
	int				y_map;
	char			**map;
	int				item_count;
	int				exit_count;
	int				hero_count;
	int				line_size;
	int				col_size;
}	t_map;

// Config pantalla
typedef struct s_show
{
	void			*mlx_ptr;
	void			*win_ptr;

	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

	int				x_win;
	int				y_win;
}	t_show;

// Info juego
typedef struct s_game
{
	struct s_character	player;
	struct s_tile		hero;
	struct s_tile		item;
	struct s_tile		exit;
	struct s_tile		wall;
	struct s_tile		floor;
	struct s_map		map;
	struct s_show		show;
}	t_game;

int	ft_printf(char const *frase, ...);
int ft_nomap(t_game *game, char *message);
int	ft_error(t_game *game, char *err_msg);
void    game_over(void);
int		init_game_structs(t_game *game);
int	is_mission_ready(t_game *game);

int	init_tile_hero(t_game *game);
int	init_tile_item(t_game *game);
int	init_tile_exit(t_game *game);
int	init_tile_floor(t_game *game);
int	init_tile_wall(t_game *game);

int	init_game_structs(t_game *game);

char	*ft_strchr(char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printchar(int c);
size_t		ft_strlen(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *string);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);

int	ft_isdigit(int c);
void	*ft_calloc(size_t numele, size_t n);
int	ft_sizeint(unsigned int n);
int	ft_printstr(const char *s);
void	ft_printhexdir_fill(char *hex, unsigned long dir_aux, int cont);
int	ft_printhexdir(unsigned long dir);
char	hex_char(int modulus, char type);
int	ft_printhex(unsigned int num, int cont, char type);
int	ft_printdigit(int num, int cont);
int	ft_printdigit_unsigned(unsigned int num);
int	ft_printchar(int c);
int		ft_printf(char const *frase, ...);

char	*get_next_line(int fd);
int		mlx_map_destroyer(t_game *game);
void	map_destroyer(t_game *game);
void	mlx_img_destroyer(t_game *game);
void	mlx_destroyer(t_game *game);

int		flood_it(t_game *game);
int		init_game_structs(t_game *game);
t_game	*map_init(char *map_name, t_game *game);
int		check_map(t_game *game);

int	closing(t_game *game);
void	motion(int keycode, t_game *game);
int	kb_input(int keycode, t_game *game);

t_game	*valid_map(char *mappy, t_game *game);

void	load_tiles(t_game *game, int x_map, int y_map);
void	move_counter(t_game *game, int mover);
void	update_display(t_game *game, int next_y, int next_x);
void	load_exit(t_game *game);
void	check_next_tile(t_game *game, int tile_code, char mod);

int	xpm_check(t_game *game);
int	xpm_addr(t_game *game);
t_game	*xpm_load(t_game *game);

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

void	display_map(t_game *game);
void	display_game(t_game *game);
int	start_game(t_game *game);

#endif