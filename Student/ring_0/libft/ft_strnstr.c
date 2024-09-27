/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:13:17 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 14:59:32 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *src);

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cont;

	cont = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		while (*big == *little)
		{
			if (cont == len)
				return ((char *)big);
			else
				little = &little[0];
			cont++;
			big++;
			little++;
		}
		cont = 0;
		big++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "abba";
	char s2[] = "cddc";
	
	printf("%s", ft_strnstr(s1, s2, 1));
	
	return (0);
}
*/
