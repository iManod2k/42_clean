/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:47:14 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/18 16:54:58 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int     ft_sizeint(int n);
int		ft_printstr(const char *s);
int		ft_printhexdir(unsigned long dir);
int 	ft_printdigit(int num, int cont);
int		ft_printf(char const *input, ...);

#endif