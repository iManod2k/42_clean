

int	    is_power_of_2(unsigned int n)
{
    if (n == 0 || n == 1)
        return (n);
    while ((n / 2) >= 1)
    {
        if ((n % 2) != 0)
            return (0);
        n /= 2;
    }
    return (1);
}

int	    is_power_of_2_bitmagic(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n & (n - 1)) == 0;
}

#include <stdio.h>

int main()
{
    int num = 0;
    while (num <= 10000)
    {
        if (is_power_of_2(num) != is_power_of_2_bitmagic(num))
        {
            printf("ERROR |%d|: %d - %d", num, is_power_of_2(num), is_power_of_2_bitmagic(num));
            return (1);
        }
        num++;
    }

    printf("ok");
}