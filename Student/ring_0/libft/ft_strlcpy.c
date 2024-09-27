/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:01:32 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 12:21:36 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	cont;

	cont = 0;
	while ((src[cont] != '\0') && cont < n)
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (cont);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "asd";
	char dest[] = "xxx";
	
	
	printf("%u\n", (unsigned int)ft_strlcpy(dest, src, 3));
	printf("%s", dest);
	
	return (0);
}
*/
