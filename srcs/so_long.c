/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:36:04 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/22 17:45:40 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include "so_long.h"
#include "../libft/libft.h"

int	main(int ac, char *argv[])
{

	t_program	game;
	
	game.map.map = ft_map(argv, &game.map);

	game.mlx = mlx_init();
	game.win = ft_new_window(game.mlx, game.map.width * 60, game.map.height * 60, "so_long");

	game.wall = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wall.xpm");
	game.wallpaper = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wallpaper.xpm");
	game.characters = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/character.xpm");
	game.exit = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/exit.xpm");
	ft_draw_map(&game, &game.wall, &game.map);
	mlx_key_hook(game.win.reference, key_hook, &game);
	mlx_loop(game.mlx);

}
