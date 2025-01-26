/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:39:23 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:39:24 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_printhexdir_fill(char *hex, unsigned long dir_aux, int cont)
{
	while (--cont >= 0)
	{
		if ((dir_aux % 16) > 0 && (dir_aux % 16) <= 9)
			hex[cont] = (dir_aux % 16) + '0';
		else if ((dir_aux % 16) >= 10 && (dir_aux % 16) <= 16)
			hex[cont] = (dir_aux % 16) - 10 + 'a';
		else
			hex[cont] = '0';
		dir_aux /= 16;
	}
}

int	ft_printhexdir(unsigned long dir)
{
	char			*hex;
	unsigned long	dir_aux;
	int				cont;

	cont = 0;
	dir_aux = dir;
	if (dir == 0)
	{
		(void)!write(1, "(nil)", 5);
		return (5);
	}
	while (dir_aux != 0)
	{
		dir_aux /= 16;
		cont++;
	}
	hex = (char *)calloc((cont + 1), sizeof(char));
	dir_aux = dir;
	ft_printhexdir_fill(hex, dir_aux, cont);
	(void)!write(1, "0x", 2);
	cont = ft_strlen(hex);
	(void)!write(1, hex, cont);
	free(hex);
	return (cont + 2);
}