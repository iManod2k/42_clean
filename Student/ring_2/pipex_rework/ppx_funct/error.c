/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:58:23 by akamal-b          #+#    #+#             */
/*   Updated: 2025/02/05 01:54:23 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_nofd(void)
{
	exit(-1);
}

void	error(void)
{
	exit(EXIT_FAILURE);
}

void	error_nocommand(void)
{
	exit(127);
}

void	error_and_exit(const char *message)
{
	perror(message);
	exit(1);
}
