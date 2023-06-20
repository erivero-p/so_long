/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:37:43 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/12 12:51:48 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"
// la eli del futuro tiene que arreglar los leaks de memoria
void	get_map(int fd, t_solong *info)
{
	char	*line;
	char	*next_line;
	char	*tmp;

	line = get_next_line(fd);
	next_line = get_next_line(fd);

	while (next_line)
	{
		tmp = ft_strjoin(line, next_line);
		next_line = get_next_line(fd);
		line = tmp;
	}
	info->map = ft_split(line, '\n');
}
