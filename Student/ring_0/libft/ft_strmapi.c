/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:41:43 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 12:42:53 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*funcion)(unsigned int str, char c));
char	funcion(unsigned int str, char c);
size_t	ft_strlen(const char *src);

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	funcion(unsigned int i, char c)
{
	return (c + i);
}

char	*ft_strmapi(char const *s, char (*funcion)(unsigned int, char))
{
	size_t	str_len;
	size_t	cont;
	char	*str;

	cont = 0;
	str_len = ft_strlen(s);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (s == 0 || funcion == 0 || str == 0)
		return (0);
	while (cont < str_len)
	{
		str[cont] = funcion(cont, s[cont]);
		cont++;
	}
	str[cont] = '\0';
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = "11111";
	char *str2;
	
	str2 = ft_strmapi(str, *funcion);
	printf("%s", str2);
	return (0);
}
*/
