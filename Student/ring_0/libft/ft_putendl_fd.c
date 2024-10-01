#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cont;

	cont = 0;
	if (!dest && !src)
		return (0);
	while (cont < n)
	{
		((char *)dest)[cont] = ((char *)src)[cont];
		cont++;
	}
	return (dest);
}
size_t	ft_strlen(char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

void ft_putendl_fd(char *s, int fd)
{
	size_t s_end;
	char *s2;
	
	s_end = ft_strlen(s);
	s2 = (char *)malloc((s_end+1) * sizeof(char));
	s2 = (char *)ft_memcpy(s2, s, s_end);
	s2[s_end] = '\n';
	write(fd, s2, s_end + 1);
	close(fd);
}
/*
int main(void)
{
	int fd;
	
	fd = open("../fichero.txt", O_WRONLY);
	ft_putendl_fd("Capricos", fd);
	return (0);
}
*/