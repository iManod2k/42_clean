#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    
    char *str = argv[1];
    char letter;
    int first_no_capital = 1;

    while (*str)
    {
        letter = *str;
        if ((first_no_capital) && letter >= 'A' && letter <= 'Z')
            letter = *str + 32;
        else if (letter >= 'A' && letter <= 'Z')
            letter = *str + 32;

        if (letter == '_')
        {
            str++;
            letter = *str;
            if (letter >= 'a' && letter <= 'z')
                letter = *str - 32;
            first_no_capital = 1;
        }else
            first_no_capital = 0;
        write(1, &letter, 1);

        str++;
        // if (first_no_capital == 1)
        // {
        //     write(1, &letter, 1);
        //     first_no_capital = 0;
        // }else
        // {
        //     write(1, &letter, 1);
        // }
        // str++;
        // while (*str && *str != '_')
        // {
        //     write(1, &*str, 1);
        //     str++;
        // }
        // if (*str)
        //     str++;
    }
    write(1, "\n", 1);
    return (0);
}