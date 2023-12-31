/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:56:58 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/26 16:11:30 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_close(t_solong *info)
{
	free_map(info, info->map);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	exit(EXIT_SUCCESS);
}

static int	ft_hook(int keycode, t_solong *info)
{
	if (keycode == ESC)
		ft_close(info);
	else if (keycode == LEFT || keycode == A)
		ft_go_left(info);
	else if (keycode == RIGHT || keycode == D)
		ft_go_right(info);
	else if (keycode == DOWN || keycode == S)
		ft_go_down(info);
	else if (keycode == UP || keycode == W)
		ft_go_up(info);
	return (0);
}

void	manage_loop(t_solong *info)
{
	mlx_key_hook(info->win_ptr, ft_hook, info);
	mlx_hook(info->win_ptr, 17, 0, ft_close, info);
	mlx_loop(info->mlx_ptr);
}
