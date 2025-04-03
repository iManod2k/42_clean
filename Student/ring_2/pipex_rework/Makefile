NAME	=	pipex
INC		= 	pipex.h

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=undefined -g
RM		=	rm -f

FILES = 	funct_aux/ft_bzero.c \
			funct_aux/ft_calloc.c \
			funct_aux/ft_putstr_with_fd.c \
			funct_aux/ft_split.c \
			funct_aux/ft_strcmp.c \
			funct_aux/ft_strdup.c \
			funct_aux/ft_strjoin.c \
			funct_aux/ft_strlcpy.c \
			funct_aux/ft_strlen.c \
			funct_aux/ft_strncmp.c \
			funct_aux/ft_substr.c \
			ppx_funct/ppx_essentials.c \
			ppx_funct/error.c \
			main.c
SRCS	=	$(FILES)

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re