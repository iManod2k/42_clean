/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:11 by jdecorte          #+#    #+#             */
/*   Updated: 2024/11/03 01:48:46 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdup(const char *s, char **duplicate)
{
	// char	*duplicate;
	size_t	s_len;
	size_t	cont;

	cont = 0;
	s_len = ft_strlen((char *)s);
	(*duplicate) = (char *)malloc((s_len + 1) * sizeof(char));
	if ((*duplicate) == NULL)
		return ;
	while (cont < s_len)
	{
		(*duplicate)[cont] = s[cont];
		cont++;
	}
	(*duplicate)[cont] = '\0';
	// return (duplicate);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		((char *)s)[cont] = '\0';
		cont++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		ps[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	ft_calloc(unsigned char **p, size_t numele, size_t n)
{
	// unsigned char	*p;
	size_t			total_size;

	if (n != 0 && numele >= SIZE_MAX / n)
        return ;
		// return (NULL);
	total_size = numele * n;
	*p = malloc(total_size);
	if (*p == NULL)
        return ;
		// return (NULL);
	ft_memset(*p, 0, total_size);
	// return (p);
}


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str || *str == '\0')
		return (i);
	while (*str != '\0')
    {
        str++;
        i++;
    }
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	pc;
	char			*ps;
	int				i;

	i = 0;
	pc = (unsigned char)c;
	ps = (char *)s;
	while (s[i] != '\0')
	{
		if (ps[i] == pc)
			return (&ps[i]);
		i++;
	}
	if (pc == '\0' && ps[i] == '\0')
		return (&ps[i]);
	return (NULL);
}

void	ft_strjoin(char **s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(*s1) + ft_strlen(s2);
    res = NULL;
	res = malloc((sizetotal + 1) * sizeof(char));
    res[sizetotal] = '\0';
    if (!res)
    {
        return ;
    }
 
	if (!res || !s2)
    {
        if (res)
        {
            free(res);
        }
		return ;
    }
    if (*s1)
    {
        while ((*s1)[i] != '\0')
        {
            res[i] = (*s1)[i];
            i++;
        }
    }
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
    if (*s1 && **s1)
    {
        free(*s1);
        *s1 = NULL;
    }
    ft_strdup(res, s1);
    free(res);
}