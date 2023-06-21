/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:37:43 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/21 12:54:15 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	get_map(int fd, t_solong *info)
{
	char	*line;
	char	*next_line;
	char	*tmp;
	int		i;

	line = get_next_line(fd);
	next_line = get_next_line(fd);
	tmp = ft_strdup("");
	i = 0;
	while (next_line)
	{
		free(tmp);
		tmp = ft_strjoin(line, next_line);
		if (i == 0)
			free(line);
		free(next_line);
		next_line = get_next_line(fd);
		line = tmp;
		i++;
	}
	info->map = ft_split(line, '\n');
	free(line);
}
