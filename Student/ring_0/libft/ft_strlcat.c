/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:23:00 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 12:26:06 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t	ft_strlen(char *src);

size_t	ft_strlen(char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dst_len;
	size_t	cont;

	cont = 0;
	dst_len = ft_strlen(dst);
	while ((src[cont] != '\0') && cont < n)
	{
		dst[dst_len + cont] = src[cont];
		cont++;
	}
	dst[cont + dst_len] = '\0';
	return (cont + dst_len);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "def";
	char dest[] = "abc";
	
	
	printf("%u\n", (unsigned int)ft_strlcat(dest, src, 2));
	size_t cont;
	
	cont = 0;
	while ( dest[cont] != '\0' ) 
	{
		printf("%c", dest[cont]);
		cont++;
	}
	
	return (0);
}
*/
