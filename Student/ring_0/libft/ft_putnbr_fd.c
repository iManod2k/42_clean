/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:47:44 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 12:48:56 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);
int		ft_sizeint_and_isnegative(int n);

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
int main(void)
{
	int fd;
	
	fd = open("../fichero.txt", O_WRONLY);
	ft_putnbr_fd(-123, fd);
	return (0);
}
*/
