#include <unistd.h>

void	print_number(int number)
{
	char c;
	if (number > 9)
		print_number(number / 10);
	c = (number % 10) + '0';
	write(1, &c, 1);
}

int main(void)
{
	int cont;

	cont = 1;
	while (cont <= 100)
	{
		if ( (cont % 3) == 0  &&  (cont % 5) == 0)
			write(1, "fizzbuzz", 8);
		else if ( (cont % 3) == 0 )
			write(1, "fizz", 4);
		else if ( (cont % 5) == 0 )
			write(1, "buzz", 4);
		else
			print_number(cont);
		write(1, "\n", 1);
		cont++;
	}
	return (0);
}