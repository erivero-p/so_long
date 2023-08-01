/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_loop_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:56:58 by erivero-          #+#    #+#             */
/*   Updated: 2023/08/01 15:41:13 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

int	bonus_close(t_solong *info)
{
	bonus_free_map(info, info->map);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	exit(EXIT_SUCCESS);
}

static void	put_movements(t_solong *info)
{
	char	*num;

	num = ft_itoa(info->movements);
	mlx_string_put(info->mlx_ptr, info->win_ptr, 27, 24, 0xFFFFFF, num);
	free(num);
}

static int	ft_hook(int keycode, t_solong *info)
{
	if (keycode == ESC)
		bonus_close(info);
	else if (keycode == LEFT || keycode == A)
		bonus_go_left(info);
	else if (keycode == RIGHT || keycode == D)
		bonus_go_right(info);
	else if (keycode == DOWN || keycode == S)
		bonus_go_down(info);
	else if (keycode == UP || keycode == W)
		bonus_go_up(info);
	put_movements(info);
	return (0);
}

void	bonus_manage_loop(t_solong *info)
{
	mlx_key_hook(info->win_ptr, ft_hook, info);
	mlx_hook(info->win_ptr, 17, 0, bonus_close, info);
	mlx_loop(info->mlx_ptr);
}
