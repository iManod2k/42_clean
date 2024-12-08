/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: akamal-b <akamal-b@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/19 11:14:11 by jdecorte		  #+#	#+#			 */
/*   Updated: 2024/11/10 20:17:26 by akamal-b		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	total_size;

	if (n != 0 && numele >= SIZE_MAX / n)
	{
		*p = NULL;
		return ;
	}
	total_size = numele * n;
	*p = malloc(total_size);
	if (*p == NULL)
		return ;
	ft_memset(*p, 0, total_size);
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

void	ft_strjoin(char **s1, char *s2, size_t i, size_t j)
{
	char	*new_str;
	size_t	len;

	if (!s1 || !s2)
		return ;
	if (*s1 == NULL)
	{
		*s1 = malloc(1);
		if (*s1 == NULL)
			return ;
		(*s1)[0] = '\0';
	}
	len = ft_strlen(*s1) + ft_strlen(s2);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return ;
	while ((*s1)[++i] != '\0')
		new_str[i] = (*s1)[i];
	while (s2[++j] != '\0')
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	free(*s1);
	*s1 = new_str;
}
