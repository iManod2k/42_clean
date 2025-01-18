/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:24:44 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 16:24:45 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_calloc(size_t numele, size_t n)
{
	unsigned char	*p;
	size_t			total_size;

	if (n != 0 && numele >= SIZE_MAX / n)
		return (NULL);
	total_size = numele * n;
	p = malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, total_size);
	return (p);
}