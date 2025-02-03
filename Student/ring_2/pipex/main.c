/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:38:48 by akamal-b          #+#    #+#             */
/*   Updated: 2025/02/03 22:21:42 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	arg_v -> ./pipex file_input CMD1 CMD2 file_output
				   0	  1		  2	   3	   4
*/
int	main(int argc, char **arg_v, char **arg_env)
{
	pid_t		process_id;
	int			pipe_fd[2];

	if (argc != 5)
	{
		ft_putstr_with_fd("Incorrect args.\n", 2);
		return (0);
	}
	if (pipe(pipe_fd) == -1)
	{
		return (ft_putstr_with_fd("Error on creating Pipe\n", 2), -1);
	}
	process_id = fork();
	if (process_id < 0)
	{
		return (ft_putstr_with_fd("Error on creating Child Proccess\n", 2), -1);
	}
	if (process_id == 0)
		ppx_child(arg_env, arg_v, pipe_fd);
	else
	{
		waitpid(process_id, NULL, 0);
		ppx_parent(arg_env, arg_v, pipe_fd);
	}
	return (0);
}
