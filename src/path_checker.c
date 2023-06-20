/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:25:28 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/20 12:30:39 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"
#include <stdlib.h>

char	**flood_fill(char **map_cpy, int x, int y)
{
	if (map_cpy[x + 1][y] == '0' || map_cpy[x + 1][y] == 'E'
		|| map_cpy[x + 1][y] == 'C')
	{
		map_cpy[x + 1][y] = 'F';
		flood_fill(map_cpy, x + 1, y);
	}
	if (map_cpy[x][y - 1] == '0' || map_cpy[x][y - 1] == 'E'
		|| map_cpy[x][y - 1] == 'C')
	{
		map_cpy[x][y - 1] = 'F';
		flood_fill(map_cpy, x, y - 1);
	}
	if (map_cpy[x - 1][y] == '0' || map_cpy[x - 1][y] == 'E'
		|| map_cpy[x - 1][y] == 'C')
	{
		map_cpy[x - 1][y] = 'F';
		flood_fill(map_cpy, x - 1, y);
	}
	if (map_cpy[x][y + 1] == '0' || map_cpy[x][y + 1] == 'E'
		|| map_cpy[x][y + 1] == 'C')
	{
		map_cpy[x][y + 1] = 'F';
		flood_fill(map_cpy, x, y + 1);
	}
	return (map_cpy);
}

static char	**map_copy(t_solong *info)
{
	char	**map_c;
	int		i;

	map_c = ft_calloc((info->height + 1), sizeof(char *));
	i = 0;
	while (i < info->height)
	{
		map_c[i] = ft_substr(info->map[i], 0, info->width);
		i++;
	}
	return (map_c);
}

static int	path_counter(t_solong *info)
{
	char	**cpy;
	int		x;
	int		y;
	int		c;

	cpy = flood_fill(map_copy(info), info->x, info->y);
	y = 0;
	c = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if ((info->map[y][x] == 'C' || info->map[y][x] == 'E')
				&& cpy[y][x] == 'F')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

bool	path_checker(t_solong *info)
{
	int	count;

	count = path_counter(info);
	if (count == info->coins + 1)
		return (true);
	else
		ft_printf("Error\nNo possible path");
	return (false);
}
