/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:12 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/03 12:47:12 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cont;

	cont = 0;
	if (!dest && !src)
		return (0);
	while (cont < n)
	{
		((char *)dest)[cont] = ((char *)src)[cont];
		cont++;
	}
	return (dest);
}
/*
int main(void)
{
	int fd;
	
	fd = open("../fichero.txt", O_WRONLY);
	ft_putendl_fd("Capricos", fd);
	return (0);
}
*/
