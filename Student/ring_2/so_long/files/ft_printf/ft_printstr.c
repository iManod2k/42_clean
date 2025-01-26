/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:39:19 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:39:20 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_printstr(const char *s)
{
	int		cont;

	cont = 0;
	if (!s)
	{
		cont = 6;
		(void)!write(1, "(null)", 6);
		return (cont);
	}
	while (*s != '\0')
	{
		cont++;
		(void)!write(1, &*s, 1);
		s++;
	}
	return (cont);
}