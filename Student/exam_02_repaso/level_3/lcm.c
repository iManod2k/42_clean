#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    int n;
    
    if (a > b)
        n = a;
    else if(b > a)
        n = b;
    while (1)
    {
        if ( (n % a == 0) && (n % b) == 0 )
            return (n);
        n++;
    }
    return (0);
}


// int main(void)
// {
//     int lcm_n = lcm((unsigned int) 800, (unsigned int) 2);
//     printf("%d", lcm_n);
//     return (0);
// }