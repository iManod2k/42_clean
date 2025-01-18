/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:25:27 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 16:25:35 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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