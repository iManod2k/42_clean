/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:30:16 by akamal-b          #+#    #+#             */
/*   Updated: 2025/01/18 18:30:27 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	closing(t_game *game)
{
	mlx_map_destroyer(game);
	return (0);
}

void	motion(int keycode, t_game *game)
{
	if (keycode == K_W || keycode == K_Z || keycode == K_AR_U)
		move_up(game);
	else if (keycode == K_A || keycode == K_Q || keycode == K_AR_L)
		move_left(game);
	else if (keycode == K_S || keycode == K_AR_D)
		move_down(game);
	else if (keycode == K_D || keycode == K_AR_R)
		move_right(game);
}

int	kb_input(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		mlx_map_destroyer(game);
	else
		motion(keycode, game);
	return (0);
}
