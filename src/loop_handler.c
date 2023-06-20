/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:56:58 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/12 16:25:04 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"
void	check_leakss(void)
{
	system("leaks -q so_long");
}

int	ft_close(t_solong *info)
{
	// hay que limpiar cosicas :D
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	atexit(check_leakss);
	exit(EXIT_SUCCESS);
}
static int ft_hook(int keycode, t_solong *info)
{
	if (keycode == ESC)
		ft_close(info);
	else if (keycode == LEFT)
		ft_go_left(info);
	else if (keycode == RIGHT)
		ft_go_right(info);
	else if (keycode == DOWN)
		ft_go_down(info);
	else if (keycode == UP)
		ft_go_up(info);
	return (0);
}

void	manage_loop(t_solong *info)
{
	mlx_key_hook(info->win_ptr, ft_hook, info);
	mlx_hook(info->win_ptr, 17, 0, ft_close, info);
	mlx_loop(info->mlx_ptr);
}
