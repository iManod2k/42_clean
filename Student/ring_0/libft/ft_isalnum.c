/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:16:38 by akamal-b          #+#    #+#             */
/*   Updated: 2024/09/19 14:56:01 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) != 0) && (ft_isdigit(c) != 0))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%i", ft_isalnum("Hola1231s"));
	return (0);
}
*/
