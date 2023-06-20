/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:35:52 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/20 12:54:49 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "../include/solong.h"

//pdte printear los tipos de errores :D

void	ft_map_dim(t_solong *info)
{
	char	**map;
	int		j;

	map = info->map;
	j = 0;
	while (map[j])
		j++;
	info->height = j;
	info->width = ft_strlen(info->map[0]);
}

static bool	shape_checker(t_solong	*info)
{
	int	height;

	height = info->height;
	while (--height > 0)
	{
		if (ft_strlen(info->map[height]) != ft_strlen(info->map[height - 1]))
		{
			ft_printf("Error\nWrong map shape");
			return (false);
		}
	}
	return (true);
}

static bool	wall_checker(t_solong	*info)
{
	int	x;
	int	y;
	int	i;

	x = info->width - 1;
	y = info->height - 1;
	i = 0;
	while (info->map[0][i])
	{
		if (info->map[0][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (info->map[y][i])
	{
		if (info->map[y][i] != '1')
			return (false);
		i++;
	}
	while (--y > 0)
		if (info->map[y][0] != '1' || info->map[y][x] != '1')
			return (false);
	return (true);
}

bool	map_checker(t_solong *info)
{
	ft_map_dim(info);
	if (!wall_checker(info))
		ft_printf("Error\nNo walls arround all map\n");
	if (wall_checker(info) && shape_checker(info)
		&& content_checker(info) && path_checker(info))
		return (true);
	return (false);
}
