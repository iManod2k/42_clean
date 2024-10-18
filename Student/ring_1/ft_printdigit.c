/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:39:14 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/18 21:14:46 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	printdigit(int num)
{
	char	n;

	if (num > 0)
		printdigit((num / 10));
	n = (num % 10) + '0';
	if (num > 0)
		write(1, &n, 1);
}

int	ft_printdigit(int num, int cont)
{
	if (num == -2147483648)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		cont++;
	}
	printdigit(num);
	return (ft_sizeint(num) + cont);
}
