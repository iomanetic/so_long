/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:45:20 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 19:50:49 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_map_init(t_map *data, t_mlx *mlx, t_game_info *game)
{
	printf(YELLOW "%s", MNV);
	free_data(data);
	free(mlx);
	free(game);
	exit(0);
}

void	check_valid(char *ag, int ac)
{
	if (ac != 2)
		non_valid_numbers_arg();
	if (!(check_file_name(ag)))
		error_file_name();
}

void	free_data(t_map *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	free(data);
}

void	ft_structure_data(t_map *data)
{
	data->collect = 0;
	data->exit = 0;
	data->x_map = 0;
	data->y_map = 0;
	data->player = 0;
	data->x_player = 0;
	data->y_player = 0;
}

int	main(int argc, char **argv)
{
	t_map		*data;
	t_mlx		*mlx;
	t_game_info	*game;

	check_valid(argv[1], argc);
	if (argc == 2)
	{
		game = (t_game_info *) malloc(sizeof(t_game_info));
		data = (t_map *) malloc(sizeof(t_map));
		mlx = (t_mlx *) malloc(sizeof(t_mlx));
		ft_structure_data(data);
		data->map = map_init(argv[1], data);
		if (!data->map[0])
			error_map_init(data, mlx, game);
		map_validation(data);
		draw_window(mlx, data, game);
		free_data(data);
	}
	return (0);
}
