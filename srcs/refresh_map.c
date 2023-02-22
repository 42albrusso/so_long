/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:23:17 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/22 17:55:29 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	ft_find_coordinates(t_map *map)
{
	int	i;
	int	j;
	t_vector coordinates;

	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			if (map->map[i][j] == 'P')
				break ;
			j++;
		}
		if (map->map[i][j] == 'P')
			break ;
		i++;
	}
	coordinates.x = j;
	coordinates.y = i;
	return(coordinates);
}

char	**ft_refresh_map(int keycode, t_program *game)
{
	t_vector	coordinates;
	char		nbr;

	coordinates = ft_find_coordinates(&game->map);
	if (keycode == 97 || keycode == 65361)
	{
		if (game->map.map[coordinates.y][coordinates.x - 1] != '1' && game->map.map[coordinates.y][coordinates.x - 1] != 'E')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y][coordinates.x - 1];
			game->map.map[coordinates.y][coordinates.x - 1] = nbr;
		}
	}
	else if (keycode == 100 || keycode == 65363)
	{
		if (game->map.map[coordinates.y][coordinates.x + 1] != '1' && game->map.map[coordinates.y][coordinates.x + 1] != 'E')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y][coordinates.x + 1];
			game->map.map[coordinates.y][coordinates.x + 1] = nbr;
		}
	}
	else if (keycode == 115 || keycode == 65364)
	{
		if (game->map.map[coordinates.y + 1][coordinates.x] != '1' && game->map.map[coordinates.y + 1][coordinates.x] != 'E')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y + 1][coordinates.x];
			game->map.map[coordinates.y + 1][coordinates.x] = nbr;
		}
	}
	else if (keycode == 119 || keycode == 65362)
	{
		if (game->map.map[coordinates.y - 1][coordinates.x] != '1' && game->map.map[coordinates.y - 1][coordinates.x] != 'E')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y - 1][coordinates.x];
			game->map.map[coordinates.y - 1][coordinates.x] = nbr;
		}
	}
	ft_draw_map(game, &game->wall, &game->map);
	return (game->map.map);
}