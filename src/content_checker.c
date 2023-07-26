/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:59:50 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/26 15:29:22 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	content_counter(t_solong *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x] == 'C')
				info->coins++;
			else if (info->map[y][x] == 'P')
			{
				info->x = x;
				info->y = y;
				info->p++;
			}
			else if (info->map[y][x] == 'E')
				info->e++;
			x++;
		}
		y++;
	}
}

static bool	characters_checker(t_solong *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x] != 'C' && info->map[y][x] != 'P'
				&& info->map[y][x] != 'E' && info->map[y][x] != '0'
				&& info->map[y][x] != '1')
			{
				ft_printf("Error\nMap contains non valid characters\n");
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	content_checker(t_solong *info)
{
	info->coins = 0;
	info->p = 0;
	info->e = 0;
	content_counter(info);
	if (characters_checker(info)
		&& info->coins > 0 && info->p == 1 && info->e == 1)
		return (true);
	if (info->coins == 0)
		ft_printf("Error\nWrong number of coins\n");
	if (info->p != 1)
		ft_printf("Error\nWrong number of characters\n");
	if (info->e != 1)
		ft_printf("Error\nWrong number of exits\n");
	return (false);
}
