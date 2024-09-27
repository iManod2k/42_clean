/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:35:42 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 15:46:37 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*strdup(const char *s);
size_t	ft_strlen(const char *src);

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	*strdup(const char *s)
{
	char	*duplicate;
	size_t	s_len;
	size_t	cont;

	cont = 0;
	s_len = ft_strlen(s);
	duplicate = (char *)malloc(s_len * sizeof(char));
	while (cont < s_len)
	{
		duplicate[cont] = s[cont];
		cont++;
	}
	return (duplicate);
}
/*
#include <stdio.h>
int main(void)
{
	char frase1[] = "Hola";
	char *frase2 = strdup(frase1);
	frase1[0] = 'X';

	printf("%s", frase2);
	return (0);
}
*/
