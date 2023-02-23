/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:36:04 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/23 15:50:18 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include "so_long.h"
#include "../libft/libft.h"

int	main(int ac, char *argv[])
{

	t_program	game;
	
	game.map.map = ft_map(argv, &game.map);
	if (ft_check_map(&game.map) == 0)
	{
		printf("C'e un errore nella mappa!");
		return (0);
	}
	game.mlx = mlx_init();
	game.win = ft_new_window(game.mlx, game.map.width * 60, game.map.height * 60, "so_long");

	game.wall = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wall.xpm");
	game.wallpaper = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/wallpaper.xpm");
	game.characters = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/character.xpm");
	game.exit = newSprite(game.mlx, "/nfs/homes/albrusso/Desktop/so_long/image/exit.xpm");
	game.collect_obj = newSprite(game.mlx, "  ");
	ft_draw_map(&game, &game.wall, &game.map);
	mlx_key_hook(game.win.reference, key_hook, &game);
	mlx_loop(game.mlx);
	free(game.map.map);
	mlx_destroy_image(game.mlx, game.characters.reference);
	mlx_destroy_image(game.mlx, game.wall.reference);
	mlx_destroy_image(game.mlx, game.wallpaper.reference);
	mlx_destroy_image(game.mlx, game.exit.reference);
}
