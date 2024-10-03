/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:40:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 12:41:02 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	cont;

	cont = 0;
	new_substr = (char *)malloc(len * sizeof(char));
	while (cont < len)
	{
		new_substr[cont] = s[cont + start];
		cont++;
	}
	new_substr[cont] = '\0';
	return (new_substr);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s", ft_substr("Hola world", 3, 10));
	return (0);
}
*/
