#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*));
void f(unsigned int c, char* str);
size_t	ft_strlen(const char *src);

size_t	ft_strlen(const char *src)
{
	size_t	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t str_len;
	size_t cont;
	
	cont = 0;
	str_len = ft_strlen(s);
	if (s != 0 && f != 0)
	{
		while (cont < str_len)
		{
			f(*s, s);
			s++;
			cont++;
		}
	}
}

void f(unsigned int c, char* str)
{
	char character;
	
	character = c + 1;
	str[0] = character;
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "Hola";
	
	ft_striteri(str, *f);
	printf("%s", str);
	return (0);
}
*/