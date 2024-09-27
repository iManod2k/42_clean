/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:02:03 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 13:38:09 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;
	char	*p1;
	char	*p2;

	cont = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	if ((*p1 == 0) || (*p2 == 0))
		return (-1);
	while ((*p1 == *p2) && cont < n)
	{
		p1++;
		p2++;
		cont++;
	}
	return (*p1 - *p2);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "abcd";
	char s2[] = "abcd";
	
	printf("%i", ft_memcmp(s1, s2, 10));
	
	return (0);
}
*/
