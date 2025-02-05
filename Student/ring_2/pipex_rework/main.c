/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:38:48 by akamal-b          #+#    #+#             */
/*   Updated: 2025/02/05 01:54:59 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	arg_v -> ./pipex file_input CMD1 CMD2 file_output
				   0	  1		  2	   3	   4
*/

static void	close_fd_and_wait(int *pipe_fd, int p1, int p2)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
}

int	main(int argc, char **arg_v, char **arg_env)
{
	pid_t		process_id1;
	pid_t		process_id2;
	int			pipe_fd[2];

	if (argc != 5)
		return (ft_putstr_with_fd("Incorrect args.\n", 2), 0);
	if (pipe(pipe_fd) == -1)
		return (ft_putstr_with_fd("Error on creating Pipe\n", 2), -1);
	process_id1 = fork();
	if (process_id1 < 0)
		return (ft_putstr_with_fd("Error on creating Child Proccess\n", 2), -1);
	if (process_id1 == 0)
		ppx_child(arg_env, arg_v, pipe_fd);
	process_id2 = fork();
	if (process_id2 < 0)
		return (ft_putstr_with_fd("Error on creating Child Proccess\n", 2), -1);
	if (process_id2 == 0)
		ppx_child2(arg_env, arg_v, pipe_fd);
	close_fd_and_wait(pipe_fd, process_id1, process_id2);
	return (0);
}
