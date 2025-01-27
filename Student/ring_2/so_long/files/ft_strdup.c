/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:07:43 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 16:08:04 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(char *string)
{
	int		i;
	char	*str_duped;

	i = -1;
	str_duped = malloc(ft_strlen(string) + 1);
	if (!str_duped)
		return (NULL);
	while (string[++i])
		str_duped[i] = string[i];
	str_duped[i] = '\0';
	return (str_duped);
}
