/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:05:04 by erivero-          #+#    #+#             */
/*   Updated: 2023/08/02 12:17:52 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

int	main(int ac, char **av)
{
	int			fd;
	t_solong	info;

	if (ac != 2)
	{
		ft_printf("Error\n Número inválido de argumentos");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n Problema al abrir el fichero");
		return (-1);
	}
	bonus_get_map(fd, &info);
	if (!map_checker(&info))
	{
		free_map(&info, info.map);
		return (-1);
	}
	info.movements = 0;
	bonus_create_window(&info);
	bonus_manage_loop(&info);
	return (0);
}
