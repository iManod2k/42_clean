/* PRUEBAS*/
#include <stdio.h>



#include <stdlib.h>

/*File descriptor manipulation*/
#include <fcntl.h>

/*Makes me able to get PID, dup & dup2*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>

size_t	ft_strlen(const char *s);
void	ft_putstr_with_fd(char *s, int file_desc);
void    ppx_child(char **arg_env, char **arg_v, int *pipe_fd);
void    ppx_parent(char **arg_env, char **arg_v, int *pipe_fd);
char    *get_path(char *command, char **arg_env);
char    *get_command_path(char *command, char **arg_env);
void	error(void);
void	error_nocommand(void);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
char	**ft_split(char const *s, char c);
int	ft_strcmp(char *s1,char *s2);
int	ft_strncmp(char *s1,char *s2, size_t n);
void	ft_free_split(char **tab);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// int	pipex(int argc, char **argv, char **arg_env);