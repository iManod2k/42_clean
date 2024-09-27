/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:28:17 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/27 16:27:07 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);
char	*fill_str(size_t start, size_t end, const char *s1);
size_t	ft_strlen(const char *src);

char	*fill_str(size_t start, size_t end, const char *s1)
{
	size_t	aux;
	char	*trimmed_str;

	aux = 0;
	trimmed_str = (char *)malloc((end - start) * sizeof(char));
	while (start < end)
	{
		trimmed_str[aux] = s1[start];
		aux++;
		start++;
	}
	trimmed_str[aux] = '\0';
	return (trimmed_str);
}

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	set_count;

	start = 0;
	end = ft_strlen(s1);
	set_count = 0;
	while (set[set_count] && set_count < ft_strlen(set))
	{
		if (set[set_count] == s1[start])
		{
			set_count = 0;
			start++;
		}
		else if (set[set_count] == s1[end - 1])
		{
			set_count = 0;
			end--;
		}
		else
			set_count++;
	}
	return (fill_str(start, end, s1));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strtrim("abaxxxzba", "abbb"));
	return (0);
}
*/
