#include <unistd.h>
#include <stdio.h>

int is_upcase(char letra)
{
    if ((letra >= 'A' && letra <= 'Z'))
        return (1);
    return (0);
}

int is_lowcase(char letra)
{
    if ( (letra >= 'a' && letra <= 'z'))
        return (1);
    return (0);
}

int is_alpha(char letra)
{
    if ( (letra >= 'a' && letra <= 'z') ||
        (letra >= 'A' && letra <= 'Z'))
        return (1);
    return (0);
}


void    ft_ulstr(char *str)
{
    int i;
    char c;

    i = 0;
    while (str[i])
    {
        c = str[i];
        if (is_lowcase(c))
            c = -('a' - c) + 'A';
        else if (is_upcase(c))
            c = -('A' - c) + 'a';
        write (1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    ft_ulstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}