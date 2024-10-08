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

size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	int		skip;

	word_count = 0;
	skip = 1;
	while (*s)
	{
		if (*s != c && skip)
		{
			skip = 0;
			word_count++;
		}else if (*s == c)													skip = 1;
		s++;
	}
	return (word_count);
}

static void	make_words(char **words, char const *s, char c, size_t n_words)
{
		char *ptr_c;

		while (*s && *s == c)
			s++;
		while (n_words--)
		{
			ptr_c = ft_strchr(s, c);
			if (ptr_c != NULL)
			{
				*words = ft_substr(s, 0, ptr_c - s);
				while (*ptr_c && *ptr_c == c)
					ptr_c++;
				s = ptr_c;
			}else
				*words = ft_substr(s, 0, ft_strlen(s) + 1);
			words++;
		}
		*words = NULL;
}

char			**ft_split(char const *s, char c)
{
	unsigned int	num_words;
	char	**words;

	if (s == NULL)
		return (NULL);
	num_words = count_words(s, c);
	words = malloc(sizeof(char **) * (num_words + 1));
	if (words == NULL)
		return (NULL);
	make_words(words, s, c, num_words);
		return (words);
}
/*
//#include <stdio.h>
int main(void)
{
	char	*string = "";
	char	letra = 'x';
	char	**string_array = ft_split(string, letra);

	printf("%s#\n", string_array[0]);
	printf("%s#\n", string_array[1]);
	printf("%s#\n", string_array[2]);

	return (0);
}
*/
