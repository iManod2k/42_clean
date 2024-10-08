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

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	return (*s1[i] - *s2[i]);
}
/*
#include <stdio.h>

int main(void)
{
	char s1[] = "as\nd";
	char s2[] = "as\0d";
	
	printf("%i", ft_strncmp(s1, s2, 3));
	
	return (0);
}
*/
