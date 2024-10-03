/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_borrar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:22 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 18:05:16 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/*
 * Main ft_lstnew
int	main(void)
{
	char *nombre1 = "Ayman";
	char *nombre2 = "Jorge";
	t_list	**objetos = (t_list **)malloc(1 * sizeof(t_list *));
		objetos[0] = ft_lstnew(nombre1);

	t_list *objeto = ft_lstnew(nombre2);
	ft_lstadd_front(objetos, objeto);
	printf("%s", ((char *)(*objetos)->next->content));
	return (0);
}
*/

/*
 * Main de FT_LSTNEW
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
*/
