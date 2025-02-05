/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:17:41 by akamal-b          #+#    #+#             */
/*   Updated: 2025/02/03 22:11:35 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	cont;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cont = 0;
	new_string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (s1[cont] != '\0')
	{
		new_string[cont] = s1[cont];
		cont++;
	}
	cont = 0;
	while (s2[cont] != '\0')
	{
		new_string[cont + s1_len] = s2[cont];
		cont++;
	}
	new_string[s1_len + s2_len] = '\0';
	return (new_string);
}
