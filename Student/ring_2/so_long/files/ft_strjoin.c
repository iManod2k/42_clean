/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:50:30 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 18:50:37 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = -1;
	j = -1;
	joined = malloc((sizeof(char) * lens1) + (sizeof(char) * lens2) + 1);
	if (joined == NULL)
		return (NULL);
	while (s1 && i++ < lens1 - 1)
		joined[i] = s1[i];
	while (s2 && j++ < lens2 - 1)
		joined[i++] = s2[j];
	joined[i] = '\0';
	return (joined);
}
