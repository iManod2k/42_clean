CC=gcc
CFLAGS=-Werror -Wextra -Wall
OUTPUTNM=output.a

bonus: main.o lstnew.o ft_lstadd_front_bonus.o 
	$(CC) lstnew_bonus.o main_borrar.o ft_lstadd_front_bonus.o -o $(OUTPUTNM) $(CFLAGS)

main.o: main_borrar.c
	$(CC) -c main_borrar.c $(CFLAGS)

lstnew.o: lstnew_bonus.c libft.h
	$(CC) -c lstnew_bonus.c  $(CFLAGS)

ft_lstadd_front_bonus.o: ft_lstadd_front_bonus.c libft.h
	$(CC) -c ft_lstadd_front_bonus.c $(CFLAGS)

# Debe cumplir estos comandos
# $(NAME)
# all
# clean
# fclean
# re
