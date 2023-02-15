/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:36:04 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/15 16:25:05 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include "so_long.h"
#include "../libft/libft.h"

int	main(void)
{

	t_program	game;
	t_image	wall;

	game.mlx = mlx_init();
	game.win = ft_new_window(game.mlx, 1320, 720, "so_long");

	wall = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wall.xpm");
	game.wallpaper = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wallpaper.xpm");
	game.characters = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/character.xpm");
	game.sprite_position.x = 60;
	game.sprite_position.y = 60;

	ft_put_wall(game.mlx, game.win, wall);
	ft_put_wallpaper(&game, game.wallpaper);
	mlx_put_image_to_window(game.mlx, game.win.reference, game.characters.reference, 60, 60);
	mlx_key_hook(game.win.reference, key_hook, &game);

	mlx_loop(game.mlx);

}


/*int	main(void)
{
	t_program	program;
	t_image	wall;
	t_image	sfondo;
	int	i;

	i = 0;
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1080, 720, "so_long");

	sfondo = newSprite(program.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/Nuoro-Prato-filato-multidirezionale-3.xpm");
	mlx_put_image_to_window(program.mlx, program.window.reference,
			sfondo.reference, 0, 0);
	program.sprite = newSprite(program.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/left.xpm");
	wall = newSprite(program.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wall.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;

	mlx_key_hook(program.window.reference, key_hook, &program);
	while (i < 22)
	{
		mlx_put_image_to_window(program.mlx, program.window.reference,
			wall.reference, 60 * i, 0);
			i++;
	}
	mlx_loop(program.mlx);
}*/
