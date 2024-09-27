/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:55:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/27 17:18:42 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
char	**ft_split(char const *s, char c);
size_t	find_delim(char const *s, char c);

size_t	find_delim(char const *s, char c)
{
	size_t	total_delims;
	size_t	cont;
	size_t	cont_aux;
	size_t	cont_delim;

	total_delims = 0;
	cont = 0;
	cont_aux = 0;
	cont_delim = 0;
	while (s[cont] != '\0')
	{
		cont_aux = cont + 1;
		while(s[cont_aux] != '\0' && s[cont_aux] == c)
		{
			cont_delim++;
			cont_aux++;
		}
		if (cont_delim >= 1)
			total_delims++;
		cont_delim = 0;
		cont++;
		cont = cont_aux;
	}
	return (total_delims);
}

char	**ft_split(char const *s, char c)
{
	char	**string;

	string = 0;
	printf("Total delims -> %lu", find_delim(s, c));
	return (string);
}

int main(void)
{
	ft_split("Hola como estas bro !       ", ' ');
	return (0);
}
