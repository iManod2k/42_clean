#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void    put_nbr(int number)
{
    char c;
    if (number > 9)
        put_nbr(number / 10);
    c = (number % 10) + '0';
    write(1, &c, 1);
}

long atol(char *str)
{
    int cont = 0;
    long num = 0;

    while (str[cont])
    {
        num = (num * 10) + (str[cont] - '0');
        cont++;
    }
    if ((num * 9) < INT_MAX && num >= 1)
        return (num);
    return (0);
}

int main(int argc, char **argv)
{
    long num = 0;
    int cont = 1;

    if (argc != 2)
        return (write(1, "\n", 1));
    num = atol(argv[1]);
    while (cont <= 9)
    {
        put_nbr((int)cont);
        write(1, " x ", 3);
        put_nbr((int)num);
        write(1, " = ", 3);
        put_nbr((int) cont * num);
        write(1, "\n", 1);
        cont++;
    }
    
    return (0);
}