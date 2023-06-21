/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:05:04 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/21 13:28:10 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

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
	get_map(fd, &info);
	if (!map_checker(&info))
		return (-1);
	info.movements = 0;
	create_window(&info);
	manage_loop(&info);
	return (0);
}
