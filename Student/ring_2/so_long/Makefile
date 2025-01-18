NAME	=	so_long
INC		= 	include/so_long.h

INCLUDES = -I/usr/include -Imlx
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

FILES = 	files/end_of_game.c \
			files/errors.c \
			files/struct_tiles_init.c \
			files/struct_init.c \
			files/map_init.c \
			files/map_ext_checker.c \
			files/map_general_checker.c \
			files/is_all_reachable.c \
			files/mlx_finishing.c \
			files/elems_position.c \
			files/start_game.c \
			files/event_hook.c \
			files/tiles.c \
			files/move.c \
			files/get_next_line.c \
			files/ft_xpm.c \
			files/ft_isdigit.c \
			files/ft_substr.c \
			files/ft_calloc.c \
			files/ft_strlen.c \
			files/ft_strdup.c \
			files/ft_strchr.c \
			files/ft_strncmp.c \
			files/ft_strjoin.c \
			files/ft_memset.c \
			files/ft_printf/ft_printdigit.c \
			files/ft_printf/ft_printhex.c \
			files/ft_printf/ft_printhexdir.c \
			files/ft_printf/ft_printstr.c \
			files/ft_printf/ft_sizeint.c \
			files/ft_printf/ft_printf.c \
			files/main.c
SRCS	=	$(FILES)

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)
$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)
$(MLX_LIB):
	@make -C $(MLX_DIR)
%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re