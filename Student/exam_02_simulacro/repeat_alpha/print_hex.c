#include <unistd.h>
#include <stdio.h>

void    write_hex(int num, char *digits)
{
    if (num > 9)
        write_hex((num / 16), digits);
    
    if (num > 0)
        write(1, &digits[ (num%16) ], 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    
    // To number
    int num = 0;
    char *str = argv[1];
    char digits[16] = "0123456789abcdef";

    while (*str)
    {
        num = (num * 10) + (*str - '0');
        str++;
    }

    if (num == 0)
    {
        write(1, "0", 1);
        return (0);
    }
    write_hex(num, digits);
    write(1, "\n", 1);
    return (0);
}