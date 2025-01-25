#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    
    char *string = argv[1];
    int cont = 0;
    int start = 0;
    int end = 0;

    while (string[cont])
    {
        while (string[cont] == ' ' || string[cont] == '\t')
            cont++;
        cont++;
    }
    write(1, "\n", 1);
    return (0);
}