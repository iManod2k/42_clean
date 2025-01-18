#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
        return (write(1, "\n", 1));

    int cont_f2 = 0;
    int cont_f1 = 0;
    while (argv[1][cont_f1])
    {
        while (argv[2][cont_f2] && (argv[2][cont_f2] != argv[1][cont_f1]) )
            cont_f2++;
        if (argv[1][cont_f1] && !argv[2][cont_f2])
            return (write(1, "0\n", 2));   
        cont_f1++;
    }
    write(1, "1\n", 2);
    return (0);
}