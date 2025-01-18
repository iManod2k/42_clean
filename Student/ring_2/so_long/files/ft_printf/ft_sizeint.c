#include "../../include/so_long.h"

int	ft_sizeint(unsigned int n)
{
	int	cont;

	cont = 1;
	while ((n / 10) != 0)
	{
		cont++;
		n = n / 10;
	}
	return (cont);
}