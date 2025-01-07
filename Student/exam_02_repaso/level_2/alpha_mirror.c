#include <unistd.h>

void    alpha_mirror(char *string)
{
	char	c;
	int 	i;
	
	i = 0;
	while (string[i])
	{
		c = string[i];
			if (string[i] >= 'a' && string[i] <= 'z')
			{
				c = (('z' - string[i]) + 'a');
				write(1, &c, 1);
			}
			else if (string[i] >= 'A' && string[i] <= 'Z')
			{
				c = (('Z' - string[i]) + 'A');
				write(1, &c, 1);
			}
			else
				write(1, &c, 1);
			i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}