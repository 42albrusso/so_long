/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:24:47 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/20 17:49:51 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall_up(char *map[], t_vector *map_size)
{
	int	j;

	j = 0;
	while(map[0][j] != '\0')
	{
		if (ft_strchr_gnl(&map[0][j], '1') == 0)
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_wall_down(char *map[], t_vector *map_size)
{
	int	j;

	j = 0;
	while (map[map_size->x - 1][j] != '\0')
	{
		if (ft_strchr_gnl(&map[map_size->x][j], '1') == 0)
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_wall_left(char *map[], t_vector *map_size)
{
	int	i;

	i = 0;
	while (i < map_size->x)
	{
		if (ft_strchr_gnl(&map[i][0], '1') == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall_right(char *map[], t_vector *map_size)
{
	int	i;

	i = 0;
	while (i < map_size->x)
	{
		if (ft_strchr_gnl(&map[i][map_size->y - 1], '1') == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_read_map_1(t_vector *map_size)
{
	int	i;
	int	fd;
	int	len;
	char	*str;

	i = 0;
	fd = open("/nfs/homes/albrusso/Desktop/so_long/maps/map.ber", O_RDONLY);
	if (fd == -1)
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (i != 0)
		{
			if (ft_strlen(str) != len)
				return (0);
		}
		len = ft_strlen(str);
		i++;
	}
	map_size->x = i;
	map_size->y = len;
	if (map_size->x == map_size->y)
		return(0);
	close(fd);
	return (1);
}

int	ft_read_map_2(char **map[], t_vector *map_size)
{
	int	i;
	int	fd;
	char	*str;

	i = 0;
	fd = open("/nfs/homes/albrusso/Desktop/so_long/maps/map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	*map =(char **)malloc(map_size->x * sizeof(char *));
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		*map[i] = ft_strdup_gnl(str);
		i++;
	}
	close(fd);
	return (1);
}

int	ft_check_wall(char *map[], t_vector *map_size)
{
	ft_check_wall_right(map, map_size);
	ft_check_wall_up(map, map_size);
	ft_check_wall_down(map, map_size);
	ft_check_wall_left(map, map_size);
	return (1);
}

int	ft_check_map(char	*map[])
{
	t_vector	map_size;
	int	i;

	i = -1;
	i = ft_read_map_1(&map_size);
	i = ft_read_map_2(&map, &map_size);
	i = ft_check_wall(map, &map_size);
	return (i);
}
