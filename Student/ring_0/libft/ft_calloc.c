/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:13:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 15:34:16 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size);

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	cont;
	void	*array;

	cont = 0;
	array = malloc(nitems * size);
	while (cont < size)
	{
		((int *)array)[cont] = 0;
		cont++;
	}
	return (array);
}
/*
#include <stdio.h>

int main(void)
{
	int *array;

	array = (int *) ft_calloc(5, sizeof(int));

	array[0] = 10;
	array[1] = 20;
	array[2] = 30;
	array[3] = 40;
	array[4] = 50;

	printf("%i\n", array[0]);
	printf("%i\n", array[1]);
	printf("%i\n", array[2]);
	printf("%i\n", array[3]);
	printf("%i\n", array[4]);



	char *frase;

	frase = (char *) ft_calloc(5, sizeof(char));

	frase[0] = 'a';
	frase[1] = 'b';
	frase[2] = 'c';
	frase[3] = 'd';
	frase[4] = 'e';

	printf("\n%s", frase);

	return (0);
}
*/
