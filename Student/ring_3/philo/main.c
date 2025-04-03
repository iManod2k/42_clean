#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 4 Argumentos. Sin el 5º opcional
int main(int argc, char **argv)
{
    if (argc != 5)
        return (EXIT_FAILURE);
    printf("%s - Bien", *argv);
    printf("\n\n");
    return (EXIT_SUCCESS);
}