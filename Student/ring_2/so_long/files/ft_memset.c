/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:52:13 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 18:52:20 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*memarea;

	memarea = (unsigned char *) s;
	while (n > 0)
	{
		*memarea = (unsigned char) c;
		memarea++;
		n--;
	}
	return (s);
}
