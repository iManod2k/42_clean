/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:29:07 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 12:30:22 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeint_and_isnegative(int n);

int	ft_sizeint_and_isnegative(int n)
{
	int	cont;

	cont = 0;
	if (n < 0)
		cont = 1;
	while (n != 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	size_t	str_size;
	char	*string;

	str_size = ft_sizeint_and_isnegative(n) - 1;
	string = (char *)malloc(str_size * sizeof(str_size + 1));
	if (string == 0)
		return (0);
	string[str_size + 1] = '\0';
	if (n < 0)
	{
		string[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		string[str_size] = (n % 10) + '0';
		str_size--;
		n = n / 10;
	}
	return (string);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s", ft_itoa(-2147483647));
	return (0);
}
*/
