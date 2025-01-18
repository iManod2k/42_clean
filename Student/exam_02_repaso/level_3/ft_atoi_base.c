#include <stdio.h>
#include <unistd.h>

int ft_atoi_base(const char *str, int base)
{
    int num = 0;
    int resul = 0;
    int cont = 0;
    int sign = 1;

    if (str[0] == '-')
    {
        cont++;
        sign = -1;
    }

    while (str[cont])
    {
        if (str[cont] >= '0' && str[cont] <= '9')
            num = str[cont] - '0';
        else if (str[cont] >= 'a' && str[cont] <= 'f')
            num = (str[cont] - 'a') + 10;
        else if (str[cont] >= 'A' && str[cont] <= 'F')
            num = (str[cont] - 'A') + 10;
        else
            break ;
        resul = (resul * base) + num;
        cont++;
    }
    return (resul * sign);
}

// int main(void)
// {
    
//     printf("%d", ft_atoi_base("12f", 10));
//     printf("\n");
//     printf("%d", ft_atoi_base("135", 16));
//     return (0);
// }