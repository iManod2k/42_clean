/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:39:10 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:39:11 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	printdigit(unsigned int num)
{
	char	n;

	if (num > 0)
		printdigit((num / 10));
	n = (num % 10) + '0';
	if (num > 0)
		(void)!write(1, &n, 1);
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
		(void)!write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		(void)!write(1, "-", 1);
		num *= -1;
		cont++;
	}
	printdigit(num);
	return (ft_sizeint(num) + cont);
}

int	ft_printdigit_unsigned(unsigned int num)
{
	if (num == 0)
	{
		(void)!write(1, "0", 1);
		return (1);
	}
	printdigit(num);
	return (ft_sizeint(num));
}