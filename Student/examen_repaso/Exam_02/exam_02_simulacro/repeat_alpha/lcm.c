unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int    div = 1;

    if (a == 0 || b == 0)
        return (0);
    
    if (a > b)
        div = a;
    else if (b > a)
        div = b;
    else
        return (a);

    while (1)
    {
        if ((div % a == 0) && (div % b == 0))
            return (div);
        div++;
    }
    return (div);
}
/*
#include <stdio.h>
int main(void)
{
    unsigned int n1 = 137;
    unsigned int n2 = 33;
    printf("%u", lcm(n1, n2));
}
*/