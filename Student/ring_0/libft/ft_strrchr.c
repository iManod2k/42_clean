/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:39:41 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 12:55:43 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *src);

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	src_len;
	size_t	cont;

	src_len = ft_strlen(s);
	cont = 0;
	if (src_len == 0)
		return (NULL);
	s += src_len - 1;
	while (*s != c && cont < src_len)
	{
		cont++;
		s--;
	}
	if (cont == src_len)
		return (NULL);
	return ((char *)s);
}
/*
#include <stdio.h>

int main(void)
{
	char src[] = "abcdefg";
	
	printf("%s", ft_strrchr(src, 'e'));
	
	return (0);
}
*/
