#include <unistd.h>
#include <fcntl.h>


void ft_putchar_fd(char c, int fd);
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	close(fd);
}
/*
int main(void)
{
	int fd;
	
	fd = open("../fichero.txt", O_WRONLY);
	ft_putchar_fd('k', fd);
	return (0);
}
*/