/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:37:43 by erivero-          #+#    #+#             */
/*   Updated: 2023/08/01 11:08:33 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

static bool	check_spaces(char *str, t_solong *info)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (i > 0 && str[i] == '\n' && str[i - 1] == '\n')
		{
			ft_printf("Error\nWrong map shape");
			free(str);
			return (false);
		}
		i++;
	}
	info->map = ft_split(str, '\n');
	return (true);
}

void	bonus_get_map(int fd, t_solong *info)
{
	char	*line;
	char	*next_line;
	char	*tmp;
	int		i;

	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
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
	if (!check_spaces(line, info))
		exit(EXIT_FAILURE);
	free(line);
}
