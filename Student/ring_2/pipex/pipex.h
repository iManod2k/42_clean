/* PRUEBAS*/
// #include <stdio.h>



#include <stdlib.h>

/*File descriptor manipulation*/
#include <fcntl.h>

/*Makes me able to get PID, dup & dup2*/
#include <unistd.h>
#include <sys/types.h>

size_t	ft_strlen(const char *s);
void	ft_putstr_withFd(char *s, int file_desc);
void    ppx_child(char **arg_env, char **arg_v, int *pipe_fd);

char	**ft_split(char const *s, char c);
void	ft_free_tab(char **tab);
// int	pipex(int argc, char **argv, char **arg_env);