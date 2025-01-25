#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void    put_num(int n)
{
    char c;

    if ((n / 10) > 0)
        put_num(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n1;
    int n2;
    int den;
    int den_max;

    if (argc != 3)
        return (write(1, "\n", 1));
    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
    den = 1;
    den_max = 1;

    while (1)
    {
        if (den == n1 || den == n2)
            break ;
        if ((n1 % den == 0) && (n2 % den == 0) )
                den_max = den;
        den++;
    }

    put_num(den_max);
    write(1, "\n", 1);

    return (0);
}