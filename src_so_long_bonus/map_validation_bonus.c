/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:32:23 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 15:07:43 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	len_validation(char **map, t_map *data)
{
	int	i;

	i = 0;
	data->x_map = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != data->x_map)
			validation_error(data);
		i++;
	}
}

void	fl_line(char *line, t_map *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			validation_error(data);
		i++;
	}
}

void	middle_line(char *line, t_map *data, int y_pos)
{
	int	x_pos;
	int	len;

	x_pos = 0;
	len = ft_strlen(line);
	while (line[x_pos])
	{
		if (line[0] != '1' || line[len - 1] != '1')
			validation_error(data);
		if (!(ft_strnchr("10CEPM", line[x_pos])))
			validation_error(data);
		if (line[x_pos] == 'P')
		{
			data->x_player = x_pos;
			data->y_player = y_pos;
			data->player++;
		}
		if (line[x_pos] == 'C')
			data->collect++;
		if (line[x_pos] == 'E')
			data->exit++;
		x_pos++;
	}
}

void	map_validation(t_map *data)
{
	int	y_pos;

	y_pos = 0;
	while (data->map[y_pos])
	{
		if (y_pos == 0 || y_pos == data->y_map - 1)
			fl_line(data->map[y_pos], data);
		else
			middle_line(data->map[y_pos], data, y_pos);
		y_pos++;
	}
	len_validation(data->map, data);
	if (data->player < 1 || data->exit < 1 || data->collect < 1)
		validation_error(data);
	if (data->x_map == data->y_map)
		validation_error(data);
}
