/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:03:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/19 14:58:35 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	return (c & ~0x7f);
}
/*
#include <stdio.h>

int main(void)
{
	if (ft_isascii(0x80))
		printf("Es ASCII");
	else
		printf("No es ASCII");

	return (0);
}
*/
