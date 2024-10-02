#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
int main(void)
{
	int *numeros = (int *)malloc(3 * sizeof(int));
	numeros[0] = 11;
    numeros[1] = 22;
    numeros[2] = 33;
	
	t_list *objeto = ft_lstnew(numeros);
	
	if (objeto == NULL)
		printf("Vaya.-.");
	else
		printf("Bien.-.");
	
	printf("%d", ((int *)objeto->content)[0]);
	return (0);
}