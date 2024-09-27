/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:55:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/27 22:15:09 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);

char **ft_split(char const *s, char c)
{
	char	**array_string;
	size_t	cont;
	size_t	cont_aux;
	size_t	letter;
	size_t	word_count;

	cont_aux = 0;
	cont = 0;
	letter = 0;
	array_string = 0; // Crear string
	word_count = 0;
	while (s[cont] != '\0')
	{
		free(array_string);
		cont_aux = cont;
		letter = 0;
		if (s[cont] == c)
		{
			word_count++;
			while (s[cont] == c)
				cont++;
			array_string = (char **)malloc(word_cont * sizeof(char *));
		}else
		{
			while (s[cont] != c)
			{
				letter++;
                                cont++;
			}
			array_string[]
		}
		
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cont;

	cont = 0;
	if (!dest && !src)
		return (0);
	while (cont < n)
	{
		((char *)dest)[cont] = ((char *)src)[cont];
		cont++;
	}
	return (dest);
}

int main(void)
{
	char	*string = "Hola como estas !";
	char	letra = ' ';

	ft_split(string, letra);
	return (0);
}
