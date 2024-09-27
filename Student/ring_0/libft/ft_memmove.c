/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:54:46 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/25 11:16:50 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	size_t	cont;

	temp = malloc (sizeof (char) * n);
	cont = 0;
	while (cont < n)
	{
		((char *)temp)[cont] = ((char *)src)[cont];
		cont++;
	}
	cont = 0;
	while (cont < n)
	{
		((char *)dest)[cont] = ((char *)temp)[cont];
		cont++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char src[5] = "123";
	char dest[10] = "456";
	
	
	printf("%s", (char*)ft_memmove(dest, src, 3));
	
	return (0);
}
*/
