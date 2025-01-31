#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(int ac, char **av, char **env)
{
    /* Prueba 1
    int file = open("fichero.txt", O_RDWR | O_CREAT, 0777);
    dup2(file, STDOUT_FILENO);
    printf("Hola bro !");
    close(file);
    */


    char buf[512];
    int cont = 0;

    int fd[2];
    int file = open("f1.txt", O_RDONLY);

    pipe(fd);

    int fork_id = fork();

    if (fork_id == 0)
    {
        write(1, "Hijo\n", 5);
        exit (0);
    }
    else
    {
        wait(NULL);
        write(1, "Padre\n", 6);
    }

    // read(file, buf, 512);
    // while (buf[cont])
    // {
    //     write(1, (&(buf[cont])), 1);
    //     cont++;
    // }

    return (0);
}