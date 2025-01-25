#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int array[256] = {0};

    if (argc != 3)
        return (write(1, "\n", 1));

    char *str1 = argv[1];
    char *str2 = argv[2];
    int cont1 = 0;
    int cont2;
    
    while (str1[cont1])
    {
        cont2 = 0;
        while (str2[cont2])
        {
            if (str1[cont1] == str2[cont2])
            {
                array[(int) str1[cont1]] = 1;
                break ;
            }
            cont2++;
        }
        cont1++;
    }

    cont1 = 0;
    while (str1[cont1])
    {
        if (array[(int) str1[cont1]] > 0)
        {
            write(1, &str1[cont1], 1);
            array[(int) str1[cont1]] = -1;
        }
        cont1++;
    }

    
    write(1, "\n", 1);
    return (0);
}