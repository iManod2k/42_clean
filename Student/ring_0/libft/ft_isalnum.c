/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:16:38 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/19 14:56:01 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char *c);
int	ft_isalpha(char c);
int	ft_isdigit(char c);

int	ft_isalnum(char *c)
{
	while (*c != '\0')
	{
		if (!ft_isalpha(*c) && !ft_isdigit(*c))
			return (0);
		c++;
	}
	return (1);
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>

int main(void)
{
	printf("%i", ft_isalnum("Hola1231s"));
	return (0);
}
*/
