#include <unistd.h>
#include <fcntl.h>

void ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *src);

size_t	ft_strlen(char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

void ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	close(fd);
}
/*
int main(void)
{
	int fd;
	
	fd = open("../fichero.txt", O_WRONLY);
	ft_putstr_fd("Hola como estas !", fd);
	return (0);
}
*/