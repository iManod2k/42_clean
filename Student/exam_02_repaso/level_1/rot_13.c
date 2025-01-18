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


void    ft_print_rot13(char *str)
{
    char c;
    int i;

    i = 0;
    while (str[i])
    {
        c = str[i];
        if (is_upcase(c))
        {
            if (!is_upcase(c+13))
                c = (((c + 13) - 'Z') + 'A') - 1;
            else
                c += 13;
        }
        else if (is_lowcase(c))
        {
            if (!is_lowcase(c+13))
                c = (((c + 13) - 'z') + 'a') - 1;
            else
                c += 13;
        }
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    ft_print_rot13(argv[1]);
    write(1, "\n", 1);
    return (0);
}