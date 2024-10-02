CC=gcc
CFLAGS=-Werror -Wextra -Wall

bonus: main.o lstnew.o
	$(CC) lstnew_bonus.o main_borrar.o -o output.exe $(CFLAGS)

main.o: main_borrar.c
	$(CC) -c main_borrar.c $(CFLAGS)

lstnew.o: lstnew_bonus.c libft.h
	$(CC) -c lstnew_bonus.c  $(CFLAGS)
# Debe cumplir estos comandos
# $(NAME)
# all
# clean
# fclean
# re