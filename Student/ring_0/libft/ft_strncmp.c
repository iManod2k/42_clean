/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:56:23 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 12:58:05 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while ((*s1 == *s2) && cont < n)
	{
		s1++;
		s2++;
		cont++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "asd";
	char s2[] = "asd";
	
	printf("%i", ft_strncmp(s1, s2, 3));
	
	return (0);
}
*/
