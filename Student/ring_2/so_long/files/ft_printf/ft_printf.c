/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:50:47 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:39:40 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_printchar(int c)
{
	(void)!write(1, &c, 1);
	return (1);
}

static int	percentaje_type(const char type, va_list args)
{
	int		cont;

	cont = 0;
	if (type == 'c')
		cont += ft_printchar(va_arg(args, int));
	else if (type == 's')
		cont += ft_printstr(va_arg(args, char *));
	else if (type == 'd')
		cont += ft_printdigit(va_arg(args, int), 0);
	else if (type == 'i')
		cont += ft_printdigit(va_arg(args, int), 0);
	else if (type == 'u')
		cont += ft_printdigit_unsigned((unsigned int)
				va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		cont += ft_printhex((unsigned int)va_arg(args, unsigned int), 1, type);
	else if (type == 'p')
		cont += ft_printhexdir((unsigned long) va_arg(args, void *));
	else if (type == '%')
		cont += ft_printchar('%');
	return (cont);
}

static int	zeros_digit_dot(const char *s, va_list args)
{
	va_list	args_copy;
	int		aux;
	int		va_num;
	int		num;

	aux = 0;
	num = 0;
	s++;
	while (ft_isdigit(*s))
		num = (num * 10) + (*(s++) - '0');
	aux = num;
	if (*(s) == 'd')
	{
		va_copy(args_copy, args);
		va_num = va_arg(args_copy, int);
		num -= ft_sizeint(va_num);
		while (num-- > 0)
			(void)!write(1, "0", 1);
		ft_printdigit(va_num, 0);
	}
	else
		return (0);
	if (aux - ft_sizeint(va_num) > 0)
		return ((aux - ft_sizeint(va_num)) + ft_sizeint(va_num));
	return (ft_sizeint(va_num));
}

static char	*skip_d(int aux, const char	*frase)
{
	if (aux > 0)
		while (*frase != 'd')
			frase++;
	return ((char *) frase);
}

int	ft_printf(char const *frase, ...)
{
	va_list		args;
	int			cont;
	int			aux;

	cont = 0;
	aux = 0;
	va_start(args, frase);
	while (*frase)
	{
		if (*frase == '%')
		{
			cont += percentaje_type(*(++frase), args);
			if (*frase == '.')
			{
				aux = zeros_digit_dot(frase, args);
				cont += aux;
				frase += ft_strlen(frase) - ft_strlen(skip_d(aux, frase));
			}
		}
		else
			cont += ft_printchar(*frase);
		frase++;
	}
	va_end(args);
	return (cont);
}