#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int    ft_strlen(char *string)
{
    int len;
    
    len = 0;
    while (string[len])
        len++;
    return (len);
}

char    *ft_strdup(char *string)
{
    int     i;
    char    *str_duped;
    
    i = -1;
    str_duped = malloc(ft_strlen(string) + 1);
		if (!str_duped)
			return (NULL);
    while (string[++i])
        str_duped[i] = string[i];
		str_duped[i] = '\0';
    return (str_duped);
}

int main(void)
{
    char string[] = "abcd ABCD\n";
		char *dup = ft_strdup(string);
    printf("%s", dup);

		free(dup);
    return 0;
}