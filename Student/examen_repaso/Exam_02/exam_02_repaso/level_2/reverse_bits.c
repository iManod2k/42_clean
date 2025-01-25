unsigned char	reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char resul = 0;

	while (i < 8)
	{
		resul = (resul * 2) + (octet % 2);
		octet /= 2;
		i++;
	}
	return (resul);
}

#include <stdio.h>
int main()
{
    // printf("%d", reverse_bits2((unsigned char)4));
    int oct = 129;
    printf("%d", reverse_bits(oct));
}