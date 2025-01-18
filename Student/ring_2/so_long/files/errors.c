/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:24:05 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 16:51:23 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_nomap(t_game *game, char *message)
{
    ft_printf("Error: %s", message);
    free(game);
    return (0);
}

int	ft_error(t_game *game, char *err_msg)
{
	ft_printf("Error: %s\nAn error has been detected", err_msg);
	map_destroyer(game);
	free(game);
	return (0);
}
