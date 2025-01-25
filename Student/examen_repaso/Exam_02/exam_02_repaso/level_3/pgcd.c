#include <unistd.h>
#include <stdio.h>
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

int	pgcd(int n1, int n2)
{
	int cont;
	int highest_common_den;

	cont = 1;
	highest_common_den = 1;
	while ( (cont <= n1) && (cont <= n2))
	{
		if ( (n1 % cont) == 0 && (n2 % cont) == 0 )
			highest_common_den = cont;
		cont++;
	}
	return (highest_common_den);
}

int main(int argc, char **argv)
{
	int n1;
	int n2;

	if (--argc == 2)
	{
		argv++;
		n1 = atoi(argv[0]);
		n2 = atoi(argv[1]);
		print_number(pgcd(n1, n2));
	}
	write(1, "\n", 1);
	return (0);
}