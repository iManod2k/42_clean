/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:28:17 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/07 17:43:02 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_str(size_t start, size_t end, const char *s1);

char	*fill_str(size_t start, size_t end, const char *s1)
{
	size_t	aux;
	char	*trimmed_str;

	aux = 0;
	trimmed_str = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (trimmed_str == NULL)
	{
		free(trimmed_str);
		trimmed_str = NULL;
		return ("");
	}
	while (start < end)
	{
		trimmed_str[aux] = s1[start];
		aux++;
		start++;
	}
	trimmed_str[aux] = '\0';
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	set_count;

	start = 0;
	end = ft_strlen(s1);
	set_count = 0;
	if (!set || !s1)
		return ((char *)s1);
	while (set[set_count] != '\0' && set_count < ft_strlen(set))
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
        char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
        char *ret = ft_strtrim(s1, " \n\t");

	printf("%s\n", s1);
	if (ret == ((void*)0))
		printf("bien");
	else
		printf("mal");
	printf("\n%s", ret);
	return (0);
}
*/
