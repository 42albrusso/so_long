/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:39:28 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/21 18:25:28 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(void	*mlx, t_window win, t_image wall)
{
	int	i;
	int	j;

	i = 0;
	while(i < 22)
	{
		j = 0;
		while (j < 18)
		{
			if (j == 0)
				mlx_put_image_to_window(mlx, win.reference, wall.reference, i * 60 , 0);
			if (i == 0)
				mlx_put_image_to_window(mlx, win.reference, wall.reference, 0 , j * 60);
			if (i == 21)
				mlx_put_image_to_window(mlx, win.reference, wall.reference, 1260 , j * 60);
			if (j == 17)
				mlx_put_image_to_window(mlx, win.reference, wall.reference, i * 60 , 660);
			j++;
		}
		i++;
	}
}

void	ft_put_wallpaper(t_program *game, t_image wallpaper)
{
	int	i;
	int	j;
	i = 1;
	while (i < 11)
	{
		j = 1;
		while(j < 21)
		{
			mlx_put_image_to_window(game->mlx, game->win.reference, wallpaper.reference, 60 * j, 60 * i);
			j++;
		}
		i++;
	}
}

void	ft_refresh_img(t_program *game, const char *s)
{
	mlx_destroy_image(game->mlx, game->characters.reference);
	game->characters = newSprite(game->mlx, s);
	mlx_put_image_to_window(game->mlx, game->win.reference,
			game->characters.reference, game->sprite_position.x, game->sprite_position.y);
}