/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:58:23 by akamal-b          #+#    #+#             */
/*   Updated: 2025/02/03 19:24:43 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(void)
{
	ft_putstr_withFd("Error", 2);
	exit(EXIT_FAILURE);
}

void	error_nocommand(void)
{
	ft_putstr_withFd("Error", 2);
	exit(127);
}