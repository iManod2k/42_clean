#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
    char c[] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    int c_cont = 7;
    while (octet > 0)
    {
        if ((octet % 2) == 0)
            c[c_cont] = '0';
        else
            c[c_cont] = '1';
        c_cont--;
        octet /= 2;
    }

    c_cont = 0;
    while (c_cont <= 7)
    {
        printf("%c", c[c_cont]);
        c_cont++;
    }
}

#include <unistd.h>

void print_bits_2(unsigned char octet)
{
	int i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		printf("%c", bit);
	}
}

int main()
{
    unsigned char octet = -5;

    print_bits(octet);
    printf("\n");
    print_bits_2(octet);
    //printf("%o", octet);
}