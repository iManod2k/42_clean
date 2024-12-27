# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 15:56:56 by akamal-b          #+#    #+#              #
#    Updated: 2024/12/27 19:44:32 by akamal-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.out
INC		= push_swap.h
AUX		=	aux_functions/
MOV		=	movements/
SORT	=	sorts/
CC			=	cc
CFLAGS	= -Wall -Werror -Wextra -g
RM			=	rm -f
COMMANDS_DIR	=	$(MOV)push.c \
								$(MOV)rev_rotate.c \
								$(MOV)rotate.c \
								$(MOV)swap.c \
								$(SORT)sort_stacks.c \
								$(SORT)move_src_dst.c \
								$(SORT)sort_three.c
PUSH_SWAP_DIR	=	push_swap.c \
								stack_init.c \
								stack_utils.c \
								init_a_to_b.c \
								init_b_to_a.c \
								errors.c \
								$(AUX)split.c \
								$(AUX)atol.c
SRCS	=	$(COMMANDS_DIR) $(PUSH_SWAP_DIR)
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re