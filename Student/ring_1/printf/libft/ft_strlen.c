/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:07:59 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/07 16:48:06 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%lu", ft_strlen(""));
	return (0);
}
*/