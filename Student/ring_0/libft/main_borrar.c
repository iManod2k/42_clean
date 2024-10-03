/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_borrar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:22 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 12:36:41 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int		*numeros;
	t_list	*objeto;

	numeros = (int *)malloc(3 * sizeof(int));
	numeros[0] = 11;
	numeros[1] = 22;
	numeros[2] = 33;
	*objeto = ft_lstnew(numeros);
	if (objeto == NULL)
		printf("Vaya.-.");
	else
		printf("Bien.-.");
	printf("%d", ((int *)objeto->content)[0]);
	return (0);
}
