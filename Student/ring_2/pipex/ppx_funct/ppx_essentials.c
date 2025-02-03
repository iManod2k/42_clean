#include "../pipex.h"

/*
    splitted_command[0] -> OG command = char *command
    
    Searches for the corresponding KEY=VALUE/bla/bla/bla

    After not finding it on the first String, goes for the next.
    
RETURNS its VALUE after the = sign -> /.../.../...
*/

char    *get_command_path(char *command, char **arg_env)
{
    int         row;
    int         col;
    char    *aux_substr;

    row = 0;
    while (arg_env[row] != NULL)
    {
        col = 0;
        while (arg_env[row][col] && arg_env[row][col] != '=')
            col++;
        aux_substr = ft_substr(arg_env[row], 0, col);
        if (ft_strcmp(aux_substr, command) == 0)
            return ( free(aux_substr), arg_env[row] + col + 1);
        free(aux_substr);
        row++;
    }
    return (NULL);
}

/*
    I get the hole command's path at allpath -> /dir/cmd:/dir2/cmd2:...

    As you can see, a single KEY can have more than 1 value, separated by ":".
    It needs to be splitted.

    Then, we join the whole path with our requested command and check
    if it Exists or can be Executed
*/
char    *get_path(char *command, char **arg_env)
{
    // int         col;
    // char    *command_to_execute;
    // char    **whole_path_no_colon;
    // char    *whole_path_filtered;
    // char    *command_splitted;
    int         row;
    char    **whole_path_no_colon;
    char    **command_splitted;
    char    *whole_path_filtered;
    char    *command_to_execute;

    row = -1;
    whole_path_no_colon = ft_split(get_command_path("PATH", arg_env), ':');
    command_splitted = ft_split(command, ' ');
    while(whole_path_no_colon[++row])
    {
        whole_path_filtered = ft_strjoin(whole_path_no_colon[row], "/");
        command_to_execute = ft_strjoin(whole_path_filtered, command_splitted[0]);
        free(whole_path_filtered);
        if (access(command_to_execute, F_OK | X_OK) == 0)
            return (ft_free_split(command_splitted), command_to_execute);
        free(command_to_execute);
    }
    ft_free_split(whole_path_no_colon);
    ft_free_split(command_splitted);
    return (command);
}

void    execute_command(char *command, char **arg_env)
{
    char    **splitted_command;
    char    *path;

    splitted_command = ft_split(command, ' ');
    path = get_path(splitted_command[0], arg_env);
    
    if (!path)
    {
        ft_free_split(splitted_command);
        error();
    }

    if (execve(path, splitted_command, arg_env) == -1)
    {
        ft_putstr_with_fd("pipex: command not found: ", 2);
        ft_putstr_with_fd(splitted_command[0], 2);
        ft_free_split(splitted_command);
        error_nocommand();
    }
}

void    ppx_child(char **arg_env, char **arg_v, int *pipe_fd)
{
    int fd;

    fd = open(arg_v[1], O_RDONLY, 0777);
    if (fd < 0)
        error();
    dup2(fd, STDIN_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[0]);
    execute_command(arg_v[2], arg_env);
}

void    ppx_parent(char **arg_env, char **arg_v, int *pipe_fd)
{
    int fd;

    fd = open(arg_v[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd < 0)
        error();
    dup2(fd, STDOUT_FILENO);
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[1]);
    execute_command(arg_v[3], arg_env);
}