/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:55:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 15:55:02 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**free_2darray(char **string);
size_t		separation_counter(char const *s, char c);
static char	**array_string_fill(const char *s, char c, char **array_string,
				size_t rows);

char	**free_2darray(char **string)
{
	size_t	cont;

	cont = 0;
	while (string[cont])
	{
		free(string[cont]);
		cont++;
	}
	free(string);
	return (NULL);
}

static char	**array_string_fill(const char *s, char c, char **array_string,
				size_t rows)
{
	size_t	rows_count;
	size_t	cols;

	cols = 0;
	rows_count = 0;
	while (*s != '\0' && rows_count < rows)
	{
		while (*s == c)
			s++;
		while (*s != c)
		{
			cols++;
			s++;
		}
		array_string[rows_count] = (char *)malloc(cols * sizeof(char));
		if (!array_string[rows_count])
			return (free_2darray(array_string));
		ft_memcpy(array_string[rows_count], (s - cols), cols);
		cols = 0;
		rows_count++;
		s++;
	}
	return (array_string);
}

size_t	separation_counter(char const *s, char c)
{
	int		breaking;
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
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array_string;
	size_t	rows;

	rows = separation_counter(s, c) + 1;
	array_string = (char **)malloc(rows * sizeof(char *));
	if (array_string == 0)
		return (free_2darray(array_string));
	array_string = array_string_fill(s, c, array_string, rows);
	array_string[rows] = (char *)malloc(1 * sizeof(char));
	if (!array_string[rows])
		return (free_2darray(array_string));
	array_string[rows][0] = '\0';
	return (array_string);
}
/*
#include <stdio.h>
int main(void)
{
	char	*string = "Hola como estas !";
	char	letra = 'a';
	char	**string_array = ft_split(string, letra);
	
	printf("%s#\n", string_array[0]);
	printf("%s#\n", string_array[1]);
	printf("%s#\n", string_array[2]);
	printf("%s#\n", string_array[3]);
	
	
	return (0);
}
*/
