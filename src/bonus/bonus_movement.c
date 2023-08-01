/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:30:22 by erivero-          #+#    #+#             */
/*   Updated: 2023/08/01 15:43:11 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

static void	ft_move(t_solong *info)
{
	bonus_put_images(info);
	info->movements++;
}

void	bonus_go_left(t_solong *info)
{
	if (info->map[info->y][info->x - 1] == '0')
	{
		info->map[info->y][info->x - 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x--;
		ft_move(info);
	}
	else if (info->map[info->y][info->x - 1] == 'C')
	{
		info->map[info->y][info->x - 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x--;
		ft_move(info);
		info->coins--;
	}
	else if (info->map[info->y][info->x - 1] == 'E' && info->coins == 0)
		bonus_close(info);
	else if (info->map[info->y][info->x - 1] == 'X')
	{
		printf("GAME OVER\n");
		bonus_close(info);
	}
}

void	bonus_go_right(t_solong *info)
{
	if (info->map[info->y][info->x + 1] == '0')
	{
		info->map[info->y][info->x + 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x++;
		ft_move(info);
	}
	else if (info->map[info->y][info->x + 1] == 'C')
	{
		info->map[info->y][info->x + 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x++;
		ft_move(info);
		info->coins--;
	}
	else if (info->map[info->y][info->x + 1] == 'E' && info->coins == 0)
		bonus_close(info);
	else if (info->map[info->y][info->x + 1] == 'X')
	{
		printf("GAME OVER\n");
		bonus_close(info);
	}
}

void	bonus_go_down(t_solong *info)
{
	if (info->map[info->y + 1][info->x] == '0')
	{
		info->map[info->y + 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y++;
		ft_move(info);
	}
	else if (info->map[info->y + 1][info->x] == 'C')
	{
		info->map[info->y + 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y++;
		ft_move(info);
		info->coins--;
	}
	else if (info->map[info->y + 1][info->x] == 'E' && info->coins == 0)
		bonus_close(info);
	else if (info->map[info->y + 1][info->x] == 'X')
	{
		printf("GAME OVER\n");
		bonus_close(info);
	}
}

void	bonus_go_up(t_solong *info)
{
	if (info->map[info->y - 1][info->x] == '0')
	{
		info->map[info->y - 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y--;
		ft_move(info);
	}
	else if (info->map[info->y - 1][info->x] == 'C')
	{
		info->map[info->y - 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y--;
		ft_move(info);
		info->coins--;
	}
	else if (info->map[info->y - 1][info->x] == 'E' && info->coins == 0)
		bonus_close(info);
	else if (info->map[info->y - 1][info->x] == 'X')
	{
		printf("GAME OVER\n");
		bonus_close(info);
	}
}
