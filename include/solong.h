/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:59:36 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/21 13:26:15 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdbool.h>

typedef struct s_solong
{
	int		height;
	int		width;
	char	**map;
	char	**map_cpy;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_ptr;
	void	*eli_ptr;
	void	*floor_ptr;
	void	*coffee_ptr;
	void	*exit_ptr;
	int		x; // coordenadas posición jugador
	int		y;
	int		movements; // tengo que decir que es 0 en el main
	int		coins;
	int		p;
	int		e;
}	t_solong;

void	get_map(int fd, t_solong *info);
bool	map_checker(t_solong *info);
void	create_window(t_solong *info);
int		ft_close(t_solong *info);
void	manage_loop(t_solong *info);
void	put_images(t_solong *info);
void	ft_go_left(t_solong *info);
void	ft_go_right(t_solong *info);
void	ft_go_down(t_solong *info);
void	ft_go_up(t_solong *info);
bool	content_checker(t_solong *info);
bool	path_checker(t_solong *info);
void	free_map(t_solong	*info, char **map);




#endif