/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:20:02 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 19:41:36 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_fd(int fd)
{
	if (fd == -1)
	{
		printf(YELLOW "%s", ERF);
		exit(0);
	}
}

void	error_map(char **line, char *j_map)
{
	if ((*line)[0] == '\n')
	{
		printf(YELLOW "%s", MNV);
		free(*line);
		free(j_map);
		exit(0);
	}
}

char	**map_init(char *ag, t_map *data)
{
	char	*line;
	char	**s_map;
	char	*tmp;
	char	*j_map;
	int		fd;

	fd = open(ag, O_RDONLY);
	error_fd(fd);
	j_map = ft_strdup("");
	while (line)
	{
		tmp = j_map;
		line = get_next_line(fd);
		if (!line)
			break ;
		error_map(&line, j_map);
		j_map = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		data->y_map++;
	}
	s_map = ft_split(j_map, '\n');
	free(j_map);
	close(fd);
	return (s_map);
}
