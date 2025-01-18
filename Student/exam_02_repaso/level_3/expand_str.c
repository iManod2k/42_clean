#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1));
    
    int i = 0;

    while (argv[1][i] == ' ' || argv[1][i] == '\t')
        i++;
    
    while (argv[1][i])
    {
        if ((argv[1][i] != ' ' && argv[1][i] != '\t') )
            write(1, &argv[1][i++], 1);
        else
        {
            while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                i++;
            if (argv[1][i])
                write(1, "   ", 3);
        }
    }
    write(1, "\n", 1);
    return (0);
}