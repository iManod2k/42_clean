
#include <stdio.h>

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

void	print_number(int number, int is_neg)
{
	char c;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		is_neg = 1;
	}
	if (number > 1)
		print_number(number/10, is_neg);
	c = number%10 + '0';
	write(1, &c, 1);
}

int		atoi(char *num)
{
	int cont;
	long final_num;
	bool neg_sign;
	
	neg_sign = false;
	final_num = 0;
	cont = 0;
	if (num[cont] == '-')
	{
			cont++;
			neg_sign = true;
	}
	while (num[cont])
	{
		final_num = (10 * final_num) + (num[cont] - '0');
		cont++;
	}
	if (neg_sign)
		final_num *= -1;

	return (final_num);
}

bool	is_num(char *num)
{
	int	cont;

	cont = 0;
	while (num[cont])
	{
		if (num[cont] == '-')
			cont++;
		if (num[cont] > '9' || num[cont] < '0')
			return (false);
		cont++;
	}
	return (true);
}

bool	is_operand(char *sign)
{
	if (*sign != '+' &&
			*sign != '-' &&
			*sign != '*' &&
			*sign != '/' &&
			*sign != '%')
			return (false);
	return (true);
}

int		operation(int n1, int n2, char *op)
{
	int resul = 0;

	if (*op == '+')
		resul = n1 + n2;
	else if (*op == '-')
		resul = n1 - n2;
	else if (*op == '*')
		resul = n1 * n2;
	else if (*op == '/')
		resul = n1 / n2;
	else if (*op == '%')
		resul = n1 % n2;
	return (resul);
}

int main(int argc, char **argv)
{
	int num1;
	int num2;
	int resul;

	if (--argc == 3)
	{
		num1 = 0;
		num2 = 0;
		resul = 0;
		argv++;
		if (is_num(argv[0]) && is_operand(argv[1]) && is_num(argv[2]))
		{
			num1 = atoi(argv[0]);
			num2 = atoi(argv[2]);
			resul = operation(num1, num2, argv[1]);
			print_number(resul, 0);
		}
	}
	write(1, "\n", 1);
	return (0);
}