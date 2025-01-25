#include <unistd.h>


void    put_nbr(int argc)
{
    char c;

    if (argc / 10 > 0)
        put_nbr(argc / 10);
    c = (argc % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    argv = argv;
    put_nbr(argc - 1);
    write(1, "\n", 1);
    return (0);
}