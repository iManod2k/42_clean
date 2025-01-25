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

int main(int argc, char **argv)
{
    int cont = 0;
    int cont_repeat = 0;

    if (argc != 2)
        return (write(1, "\n", 1));
    while (argv[1][cont])
    {
        cont_repeat = 0;
        if (is_lowcase(argv[1][cont]))
            cont_repeat = -('a' - argv[1][cont]);
        if (is_upcase(argv[1][cont]))
            cont_repeat = -('A' - argv[1][cont]);
        while (cont_repeat-- >= 0)
                write(1, &argv[1][cont], 1);
        cont++;
    }
    write(1, "\n", 1);
    return (0);
}