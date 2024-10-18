/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:24:15 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/18 21:15:08 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *s)
{
	int		cont;

	cont = 0;
	if (!s)
	{
		cont = 6;
		write(1, "(null)", 6);
		return (cont);
	}
	while (*s != '\0')
	{
		cont++;
		write(1, &*s, 1);
		s++;
	}
	return (cont);
}
