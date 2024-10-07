/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:00:15 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/07 14:02:42 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	cont;
	int	sign;
	int	num;

	cont = 0;
	sign = 1;
	num = 0;
	while ((nptr[cont] >= 9 && nptr[cont] <= 13) || nptr[cont] == 32)
		cont++;
	while ((nptr[cont] == '+' || nptr[cont] == '-'))
	{
		if (nptr[cont] == '-')
			sign *= -1;
		cont++;
	}
	while ((nptr[cont] >= '0' && nptr[cont] <= '9'))
	{
		num = (num * 10) + nptr[cont] - '0';
		cont++;
	}
	return (num * sign);
}
/*
#include <stdio.h>

int main(void)
{
	
	int num = ft_atoi("321-123");
	
	printf("%i", num);
	
	return (0);
}
*/
