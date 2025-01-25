#include <unistd.h>

void	print_them(unsigned char octet, int times)
{
    if (times > 1)
        print_them(octet / 2, times - 1 );
    if ( (octet % 2) == 0)
        write(1, "0", 1);
    else if ( (octet % 2) == 1)
        write(1, "1", 1);
}

void	print_bits(unsigned char octet)
{
    print_them(octet, 8);
}

int main(void)
{
    print_bits((unsigned char) 500);
    return (0);
}