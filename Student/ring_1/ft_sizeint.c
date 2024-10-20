/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:54:40 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/20 19:23:22 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizeint(unsigned int n)
{
	int	cont;

	cont = 1;
	while ((n / 10) != 0)
	{
		cont++;
		n = n / 10;
	}
	return (cont);
}
