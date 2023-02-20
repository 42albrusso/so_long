/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:17 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/20 17:05:28 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "../minilibx_linux/mlx.h"
#include <stdio.h>


int	key_hook(int keycode, void *g)
{
	t_program	*game;
	t_vector	old;

	game = (t_program *)g;
	old.x = game->sprite_position.x;
	old.y = game->sprite_position.y;
	if (keycode == 65307)
		exit(0);
	if (keycode == 97 || keycode == 65361)
	{
		if (game->sprite_position.x - 60 > 0)
			game->sprite_position.x -= 60;
	}
	else if (keycode == 100 || keycode == 65363)
	{
		if (game->sprite_position.x + 60 < (game->win.size.x - 60))
			game->sprite_position.x += 60;

	}
	else if (keycode == 115 || keycode == 65364)
	{
		if (game->sprite_position.y + 60 < (game->win.size.y - 60))
			game->sprite_position.y += 60;
	}
	else if (keycode == 119 || keycode == 65362)
	{
		if (game->sprite_position.y - 60 > 0)
			game->sprite_position.y -= 60;
	}
	
	mlx_put_image_to_window(game->mlx, game->win.reference, game->wallpaper.reference, old.x, old.y);
	ft_refresh_img(game);
	printf("keycode: %d\n", keycode);
	return (0);
}
