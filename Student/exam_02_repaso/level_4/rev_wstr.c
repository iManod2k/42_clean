#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    
    char *str = argv[1];
    
    int start;
    int end;
    int cont = 0;

    while (str[cont] != '\0')
        cont++;
    while (cont >= 0)
    {
        while (str[cont] && (str[cont] == ' ' || str[cont] == '\t'))
            cont--;
        end = cont;
        while (str[cont] && (str[cont] != ' ' && str[cont] != '\t'))
            cont--;
        start = cont + 1;
        while (start <= end)
            write(1, &str[start++], 1);
        if (str[cont] == ' ')
            write(1, " ", 1);
        cont--;
    }
    write(1, "\n", 1);
    return (0);
}