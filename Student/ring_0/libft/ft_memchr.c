/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:01:03 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 13:01:39 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const char *s, int c, size_t n);

void	*ft_memchr(const char *s, int c, size_t n)
{
	size_t	cont;

	cont = 0;
	while (*s != c && cont < n)
	{
		cont++;
		s++;
	}
	if (cont == n)
		return (NULL);
	return ((char *)s);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "abcdefghijklm";
	
	printf("%s", (char *)ft_memchr(s1, 'd', 4));
	
	return (0);
}
*/
