#include "../pipex.h"

/*
    splitted_command[0] -> OG command
    splitted_command[n+1] -> command Args
*/
void    execute_command(char *command, char **arg_env)
{
    char    **splitted_command;
    char    *path;

    splitted_command = ft_split(command, ' ');
    path = get_path(splitted_command);
}

void    ppx_child(char **arg_env, char **arg_v, int *pipe_fd)
{
    int fd;

    ft_putstr_withFd("Child:\n", 1);
    fd = open(arg_v[1], O_RDONLY, 0777);
    close(pipe_fd[0]);
    dup2(fd, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    execute_command(arg_v[2], arg_env);
    return ;
}