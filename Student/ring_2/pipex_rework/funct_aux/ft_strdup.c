/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:29:09 by akamal-b          #+#    #+#             */
/*   Updated: 2025/02/03 22:08:03 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	s_len;
	size_t	cont;

	cont = 0;
	s_len = ft_strlen(s);
	duplicate = (char *)malloc((s_len + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (cont < s_len)
	{
		duplicate[cont] = s[cont];
		cont++;
	}
	duplicate[cont] = '\0';
	return (duplicate);
}
