/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:30:22 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/12 16:15:26 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_go_left(t_solong *info)
{
	if (info->map[info->y][info->x - 1] == '0')
	{
		info->map[info->y][info->x - 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x--;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
	}
	else if (info->map[info->y][info->x - 1] == 'C')
	{
		info->map[info->y][info->x - 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x--;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
		info->coins--;
	}
	else if (info->map[info->y][info->x - 1] == 'E' && info->coins == 0)
		ft_close(info);
}

void	ft_go_right(t_solong *info)
{
	if (info->map[info->y][info->x + 1] == '0')
	{
		info->map[info->y][info->x + 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x++;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
	}
	else if (info->map[info->y][info->x + 1] == 'C')
	{
		info->map[info->y][info->x + 1] = 'P';
		info->map[info->y][info->x] = '0';
		info->x++;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
		info->coins--;
	}
	else if (info->map[info->y][info->x + 1] == 'E' && info->coins == 0)
		ft_close(info);
}

void	ft_go_down(t_solong *info)
{
	if (info->map[info->y + 1][info->x] == '0')
	{
		info->map[info->y + 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y++;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
	}
	else if (info->map[info->y + 1][info->x] == 'C')
	{
		info->map[info->y + 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y++;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
		info->coins--;
	}
	else if (info->map[info->y + 1][info->x] == 'E' && info->coins == 0)
		ft_close(info);
}

void	ft_go_up(t_solong *info)
{
	if (info->map[info->y - 1][info->x] == '0')
	{
		info->map[info->y - 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y--;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
	}
	else if (info->map[info->y - 1][info->x] == 'C')
	{
		info->map[info->y - 1][info->x] = 'P';
		info->map[info->y][info->x] = '0';
		info->y--;
		put_images(info);
		info->movements++;
		ft_printf("número de movimientos: %i\n", info->movements);
		info->coins--;
	}
	else if (info->map[info->y - 1][info->x] == 'E' && info->coins == 0)
		ft_close(info);
}
