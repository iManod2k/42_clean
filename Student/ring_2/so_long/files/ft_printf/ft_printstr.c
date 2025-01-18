#include "../../include/so_long.h"

int	ft_printstr(const char *s)
{
	int		cont;

	cont = 0;
	if (!s)
	{
		cont = 6;
		(void)!write(1, "(null)", 6);
		return (cont);
	}
	while (*s != '\0')
	{
		cont++;
		(void)!write(1, &*s, 1);
		s++;
	}
	return (cont);
}