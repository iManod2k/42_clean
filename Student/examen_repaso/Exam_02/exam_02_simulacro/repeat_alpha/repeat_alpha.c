#include <unistd.h>

#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));

    char *str = argv[1];
    int cont = 0;
    int cont_aux = 0;
    char letter;
    while (str[cont])
    {
        letter = str[cont];
        if (letter >= 'a' && letter <= 'z')
            cont_aux = (letter - 'a');
        else if (letter >= 'A' && letter <= 'Z')
            cont_aux = (letter - 'A');
        else
            cont_aux = 0;
        while (  cont_aux >= 0)
        {
            write(1, &letter, 1);
            cont_aux--;
        }
        cont++;
    }
    write(1, "\n", 1);
    return (0);
}