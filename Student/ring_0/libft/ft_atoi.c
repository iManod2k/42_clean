/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:00:15 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 15:04:19 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *nptr);
int	ft_pow(int num, int pow);

int	ft_pow(int n, int pow)
{
	int	num;

	num = 1;
	if (pow <= 0)
		return (1);
	while (pow > 0)
	{
		num *= n;
		pow--;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	cont;
	int	cont_aux;
	int	diez;

	num = 0;
	cont = 0;
	cont_aux = 0;
	diez = 1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nptr++;
		cont++;
	}
	nptr -= cont;
	while (cont > 0)
	{
		num += ft_pow(10, cont - 1) * (*nptr - '0');
		cont--;
		nptr++;
	}
	return (num);
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
