/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:49:48 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/17 19:12:07 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_prcnt_type(const char c,
					const va_list args, const int fd);
static void		digits(const char **s_aux,
					const va_list args, const int fd);
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

static void	xtoa_format(size_t hex,
					const char letter_type, int format, const int fd)
{
	char	*nums;
	int		format_aux;
	size_t	hex_aux;
	size_t	hex_aux_mod;

	format_aux = format;
	hex_aux = hex;
	nums = (char *)malloc((format + 1) * sizeof(char));
	if (!nums)
	{
		write(fd, "", 1);
		return ;
	}
	hex_aux = hex;
	while (format-- > 0)
	{
		hex_aux_mod = (hex_aux % 16);
		if (hex_aux_mod > 0 && hex_aux_mod <= 9)
			nums[format] = hex_aux_mod + '0';
		else if (hex_aux_mod >= 10 && hex_aux_mod <= 16)
			nums[format] = (letter_type - 23) + (hex_aux_mod - 10);
		else
			nums[format] = '0';
		hex_aux /= 16;
	}
	write(fd, nums, format_aux);
	free(nums);
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
		free(aux);
	}
	else if (c == 'c')
	{
		c_aux = (char)va_arg(args, int);
		write(fd, &c_aux, 1);
	}
	else if (c == 's')
	{
		aux = va_arg(args, char *);
		write(fd, aux, ft_strlen(aux));
		free(aux);
		//write(fd, va_arg(args, char *), ft_strlen(va_arg(args, char *)));
	}
	else if (c == 'p')
	{
		hex = (size_t) va_arg(args, void *);
		write(fd, "0x", 2);
		xtoa_format((size_t) hex, 'x', 12, fd);
	}
	else if (c == 'x' || c == 'X')
		xtoa_format((size_t) va_arg(args, int), c, 8, fd);
}

int	ft_printf(char const *frase, ...)
{
	va_list	args;
	int		fd;
	int		cont;

	va_start(args, frase);
	fd = STDOUT_FILENO;
	cont = 0;
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
			{
				print_prcnt_type((*(++frase)), args, fd);
				cont++;
			}
		}
		else
			write(fd, &*frase, 1);
		frase++;
	}
	va_end(args);
	return (cont);
}

/*
#include <stdio.h>
int	main(void)
{
	
	// char *frase = (char *)malloc((4 + 1)* sizeof(char));
	// ft_strlcpy(frase, "Hola", 4);
	// printf("%p\n", &frase);
	// ft_printf("%p\n", &frase);

	// char *frase = (char *)malloc((4 + 1)* sizeof(char));
	// ft_strlcpy(frase, "Hola", 5);
	// printf("%s\n", frase);
	// ft_printf("%s\n", frase);
	
	// int number = -14423;
	// printf("printf: %x - %X\n", (int)number, (int)number);
	// ft_printf("ft_printf: %x - %X\n", (int)number, (int)number);
	
	ft_printf(" %c ", '0');

	return (0);
}
*/