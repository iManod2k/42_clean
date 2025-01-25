#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void	print_number(int number)
{
	char c;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	if (number > 9)
		print_number(number/10);
	c = number%10 + '0';
	write(1, &c, 1);
}

int		ft_atoi(char *num)
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

void	fprime(char *str_num)
{
	int num;
	int cont;

	num = ft_atoi(str_num);
	cont = 1;
	while (cont <= num)
	{
		while ((num % cont) == 0)
		{
			if (cont == 1)
				cont++;
			else
			{
				print_number(cont);
				write(1, "*", 1);
				num /= cont;
			}
		}
		cont++;
	}
}

int main(int argc, char **argv)
{

	if (--argc != 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	fprime(argv[1]);
	write(1, "\n", 1);
	return (0);
}