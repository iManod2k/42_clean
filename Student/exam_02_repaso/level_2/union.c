#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char letters[256] = {0};
    unsigned char letter;
    int cont;
    cont = 0;

    if (argc != 3)
        return (write(1, "\n", 1));
    while (argv[1][cont])
    {
        letter = argv[1][cont];
        if (!letters[letter])
        {
            letters[letter] = 1;
            write(1, &letter, 1);
        }
        cont++;
    }
    cont = 0;
    while (argv[2][cont])
    {
        letter = argv[2][cont];
        if (!letters[letter])
        {
            letters[letter] = 1;
            write(1, &letter, 1);
        }
        cont++;
    }

    printf("%s", letters);
    write(1, "\n", 1);
    return (0);
}