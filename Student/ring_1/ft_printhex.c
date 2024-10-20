/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:33:16 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/20 19:22:58 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	hex_char(int modulus, char type)
{
	if (modulus > 0 && modulus <= 9)
		return (modulus + '0');
	else if (modulus >= 10 && modulus <= 16)
		return ((modulus - 10) + (type - 23));
	return ('0');
}

int	ft_printhex(unsigned int num, int cont, char type)
{
	int				aux_str_size;
	unsigned int	aux_num;
	char			*str;

	aux_str_size = 0;
	aux_num = num;
	while ((aux_num / 16) != 0)
	{
		aux_num /= 16;
		cont++;
	}
	str = (char *)malloc((cont + 1) * sizeof(char));
	if (!str)
		return (0);
	str[cont--] = '\0';
	while (cont >= 0)
	{
		str[cont--] = hex_char((int)(num % 16), type);
		num /= 16;
	}
	aux_str_size = ft_printstr(str);
	free(str);
	return (aux_str_size);
}
