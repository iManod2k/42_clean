#include <stdlib.h>
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;
	size_t	cont;
	
	cont = 0;
	new_substr = (char *)malloc(len * sizeof(char));
	while (cont < len)
	{
		new_substr[cont] = s[cont + start];
		cont++;
	}
	new_substr[cont] = '\0';
	return (new_substr);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s", ft_substr("Hola world", 3, 10));
	return (0);
}
*/
