/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_window_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:46:29 by erivero-          #+#    #+#             */
/*   Updated: 2023/08/01 17:06:35 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

void	bonus_create_image(t_solong *info)
{
	int	size;

	size = 64;
	info->wall_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/wall.xpm", &size, &size);
	info->eli_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/eli.xpm", &size, &size);
	info->floor_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/floor.xpm", &size, &size);
	info->coffee_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/coffee.xpm", &size, &size);
	info->exit_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/exit.xpm", &size, &size);
	info->enemy_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/enemy.xpm", &size, &size);
	info->enemy2_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/enemy2.xpm", &size, &size);
	info->movements_ptr = mlx_xpm_file_to_image
		(info->mlx_ptr, "sprites/movements.xpm", &size, &size);
}

static void	image_handler(t_solong *info, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window
		(info->mlx_ptr, info->win_ptr, img_ptr, x * 64, y * 64);
}

static void	put_enemies(t_solong *info, int x, int y)
{
	if (!(x == 0 && y == 0))
	{
		image_handler(info, info->floor_ptr, x, y);
		if (info->map[y][x] == '1')
			image_handler(info, info->wall_ptr, x, y);
		else if (info->map[y][x] == 'P')
			image_handler(info, info->eli_ptr, x, y);
		else if (info->map[y][x] == 'C')
			image_handler(info, info->coffee_ptr, x, y);
		else if (info->map[y][x] == 'E')
			image_handler(info, info->exit_ptr, x, y);
		else if (info->map[y][x] == 'X')
		{
			if (info->movements % 2 == 0)
				image_handler(info, info->enemy_ptr, x, y);
			else
				image_handler(info, info->enemy2_ptr, x, y);
		}
	}
}

void	bonus_put_images(t_solong *info)
{
	int	y;
	int	x;

	y = 0;
	image_handler(info, info->floor_ptr, 0, 0);
	image_handler(info, info->movements_ptr, 0, 0);
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			put_enemies(info, x, y);
			x++;
		}
		y++;
	}
}

void	bonus_create_window(t_solong *info)
{
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->width * 64, info->height * 64, "elili needs a coffee or two");
	bonus_create_image(info);
	bonus_put_images(info);
}
