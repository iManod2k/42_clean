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

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
size_t	separation_counter(char const *s, char c);

size_t	separation_counter(char const *s, char c)
{
	int	breaking;
	size_t	count;
	
	count = 0;
	breaking = 0;
	while (*s != '\0')
	{
		while (*s == c)
		{
			breaking = 1;
			s++;
		}
		if (breaking)
			count++;
		breaking = 0;
		s++;
	}
	return count;
}

char **ft_split(char const *s, char c)
{
	char 	**array_string;
	size_t	rows;
	size_t	rows_count;
	size_t	cols;
	
	rows = separation_counter(s, c) + 1;
	rows_count = 0;
	array_string = (char**)malloc(rows * sizeof(char*));
	cols = 0;
	if (!array_string)
			return (0);
	while (*s != '\0' && rows_count < rows)
	{
		while (*s == c)
			s++;
		while (*s != c)
		{
			cols++;
			s++;
		}
		array_string[rows_count] = (char*)malloc(cols * sizeof(char));
		if (!array_string[rows_count])
			return (0);
		ft_memcpy(array_string[rows_count], (s - cols), cols);
		cols = 0;
		rows_count++;
			s++;
	}
	//free(array_string[rows_count]);
	array_string[rows_count] = (char*)malloc(1 * sizeof(char));
	array_string[rows_count][0] = '\0';
	return (array_string);
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
	((char *)dest)[cont] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char	*string = "Hola como estas !";
	char	letra = 'a';
	char	**string_array = ft_split(string, letra);
	
	printf("%s\n", string_array[0]);
	printf("%s\n", string_array[1]);
	printf("%s\n", string_array[2]);
	printf("%s\n", string_array[3]);
	
	
	return (0);
}
*/