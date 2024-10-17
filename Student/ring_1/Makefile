# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 17:13:53 by akamal-b          #+#    #+#              #
#    Updated: 2024/10/17 17:16:37 by akamal-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)



all: $(NAME)

makelibft:
		@make -C $(LIBFTDIR)
		@cp $(LIBFTDIR)/$(LIBFTNAME) .
		@mv	$(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
		@ar -r $(NAME) $(OBJS)

clean:
		@rm -f $(OBJS)
		@cd $(LIBFTDIR) && make clean

fclean: clean
		@rm -f $(NAME)
		@cd $(LIBFTDIR) && make fclean

re: fclean all