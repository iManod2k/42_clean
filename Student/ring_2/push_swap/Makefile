NAME	=	push_swap

INC		= push_swap.h
AUX		=	aux_functions/
MOV		=	movements/
SORT	=	sorts/

CC			=	cc
CFLAGS	= -Wall -Werror -Wextra
RM			=	rm -f

COMMANDS_DIR	=	$(MOV)push.c \
								$(MOV)rev_rotate.c \
								$(MOV)rotate.c \
								$(MOV)swap.c \
								$(SORT)sort_stacks.c \
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

all:$(NAME)
$(NAME):$(OBJS) $(INC)
	@ar rcs $(NAME) $(OBJS)
%.o: %.c $(INC)
	$(CC)  $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

rm: fclean all
# OBJ = $(patsubst %.c, %.o, $(SRCS))

# start:
# 	@make all
# all:	$(NAME)
# $(NAME):	$(OBJ)
# 	@$(CC) $(CFLAGS) $(HEAD) $(OBJ) -o $(NAME)

# %.o:	%.c
# 	@mkdir -p $(@D)
# 	@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
# clean:
# 	@$(RM) -r %.o
# fclean:	clean
# 	@$(RM) $(NAME)
# re:	fclean all
# .PHONY: 			start all clean fclean re