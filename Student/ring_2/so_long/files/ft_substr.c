/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:05:28 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 17:08:18 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copie;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (NULL);
	while (len-- > 0 && s[start + i])
	{
		copie[i] = s[start + i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}
