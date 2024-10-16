/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:49:48 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/17 01:23:10 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

static void		print_prcnt_type(const char c,
					const va_list args, const int fd);
static void		digits(const char **s_aux,
					const va_list args, const int fd);
static char		xtoa(size_t hex, const char letter_type);
static void		xtoa_format(size_t hex,
					const char letter_type, int format, const int fd);
static void		ft_print_unsigned(unsigned int n, const int fd);
int				ft_sizeint(int n);

static void	ft_print_unsigned(unsigned int n, const int fd)
{
	unsigned char	c;

	c = 0;
	if (n > 0)
	{
		c = (n % 10) + '0';
		ft_print_unsigned((n / 10), fd);
	}
	write(fd, &c, 1);
}

static void	digits(const char **s_aux, const va_list args, const int fd)
{
	int	digit;
	int	d_zero_count;
	int	d_resul;

	digit = 0;
	d_zero_count = 0;
	d_resul = 0;
	while (ft_isdigit(**(s_aux)))
	{
		d_resul = (d_resul * 10) + (**s_aux - '0');
		d_zero_count++;
		*s_aux += 1;
	}
	digit = va_arg(args, int);
	while ((d_resul - ft_sizeint(digit)) > 0)
	{
		write(fd, "0", 1);
		d_resul--;
	}
	write(fd, ft_itoa(digit), ft_sizeint(digit));
}

static char	xtoa(size_t hex, const char letter_type)
{
	size_t	hex_aux;
	char	letter;

	letter = 'a';
	hex_aux = 0;
	if (letter_type == 'X')
		letter = 'A';
	hex_aux = hex % 16;
	if (hex_aux > 0 && hex_aux <= 9)
		return (hex_aux + '0');
	else if (hex_aux >= 10 && hex_aux <= 16)
		return ((hex_aux - 10) + letter);
	return ('0');
}

static void	xtoa_format(size_t hex,
					const char letter_type, int format, const int fd)
{
	char	*nums;
	size_t	hex_aux;

	hex_aux = hex;
	nums = (char *)malloc((format + 1) * sizeof(char));
	if (!nums)
	{
		write(fd, "", 1);
		return ;
	}
	hex_aux = hex;
	while (format > 0)
	{
		nums[--format] = xtoa((hex_aux % 16), letter_type);
		hex_aux /= 16;
	}
	write(fd, nums, ft_strlen(nums));
}

static void	print_prcnt_type(const char c, const va_list args, const int fd)
{
	void			*aux;
	unsigned int	ui_aux;
	size_t			hex;
	unsigned char	c_aux;

	hex = 0;
	if (c == '%')
		write(fd, "%", 1);
	else if (c == 'u')
	{
		ui_aux = (unsigned int)va_arg(args, unsigned int);
		ft_print_unsigned(ui_aux, fd);
	}
	else if (c == 'i' || c == 'd')
	{
		aux = ft_itoa(va_arg(args, int));
		write(fd, aux, ft_strlen(aux));
	}
	else if (c == 'c')
	{
		c_aux = va_arg(args, int);
		write(fd, &c_aux, 1);
	}
	else if (c == 's')
	{
		aux = va_arg(args, char *);
		write(fd, aux, ft_strlen(aux));
	}
	else if (c == 'p')
	{
		hex = (size_t) va_arg(args, void *);
		write(fd, "0x", 2);
		xtoa_format((size_t) hex, c, 12, fd);
	}
	else if (c == 'x' || c == 'X')
		xtoa_format((size_t) va_arg(args, int), c, 8, fd);
}

int	ft_printf(char const *frase, ...)
{
	va_list	args;
	int		fd;

	va_start(args, frase);
	fd = STDOUT_FILENO;
	if (!frase)
		return (0);
	while (*frase)
	{
		if (*frase == '%')
		{
			if (*(frase + 1) == '.' && ft_isdigit(*(frase + 2)))
			{
				frase += 2;
				digits(&frase, args, fd);
			}
			else
				print_prcnt_type((*(++frase)), args, fd);
		}
		else
			write(fd, &*frase, 1);
		frase++;
	}
	va_end(args);
	return (0);
}
/*
int	main(void)
{
	
	//char *frase = (char *)malloc((4 + 1)* sizeof(char));
	
	//ft_strlcpy(frase, "Hola", 4);
	//("%p\n", &frase);
	//ft_("%p\n", &frase);
	

	
	// size_t number = -5;
	// (": %x - %X\n", (int)number, (int)number);
	// ft_("ft_: %x - %X\n", (int)number, (int)number);
	
	unsigned int number = 3147483648;
	ft_printf("ft_print: %u\n", number);

	return (0);
}
*/