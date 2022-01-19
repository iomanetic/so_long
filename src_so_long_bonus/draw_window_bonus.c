/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:07:43 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 17:19:21 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_structgame(t_game_info *game, t_map *data)
{
	game->px_block_x = 32;
	game->px_block_y = 32;
	game->score_game = 0;
	game->size_map_x = game->px_block_x * data->x_map;
	game->size_map_y = game->px_block_y * data->y_map + 32;
}

void	draw_map(t_mlx *mlx, t_game_info *game, t_map *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		draw_block(data->map[i], mlx, game, i);
		i++;
	}
}

void	draw_cpe(t_mlx *mlx, char symb, int x_map, int y_map)
{
	if (symb == 'C')
	{
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_floor, x_map * 32, y_map * 32);
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_collect, x_map * 32, y_map * 32);
	}
	if (symb == 'P')
	{
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_floor, x_map * 32, y_map * 32);
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_player, x_map * 32, y_map * 32);
	}
	if (symb == 'E')
	{
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_floor, x_map * 32, y_map * 32);
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_exit, x_map * 32, y_map * 32);
	}
}

void	draw_block(char *line, t_mlx *mlx, t_game_info *game, int y_map)
{
	int	x_map;

	x_map = 0;
	while (line[x_map])
	{
		if (line[x_map] == '1')
		{
			mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
				mlx->img_floor, x_map * 32, y_map * 32);
			mlx_put_image_to_window(mlx->mlx_init,
				mlx->mlx_win, mlx->img_wall, x_map * 32, y_map * 32);
		}
		if (line[x_map] == '0')
			mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
				mlx->img_floor, x_map * 32, y_map * 32);
		if (line[x_map] == 'M')
		{
			mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
				mlx->img_floor, x_map * 32, y_map * 32);
			mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
				mlx->img_mob, x_map * 32, y_map * 32);
		}
		draw_cpe(mlx, line[x_map], x_map, y_map);
		x_map++;
	}
}

void	draw_window(t_mlx *mlx, t_map *data, t_game_info *game)
{
	ft_structgame(game, data);
	mlx->mlx_init = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_init,
			game->size_map_x, game->size_map_y, "SO_LONG");
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx_init,
			WALL_B, &game->px_block_x, &game->px_block_y);
	mlx->img_floor = mlx_xpm_file_to_image(mlx->mlx_init,
			FLOOR_B, &game->px_block_x, &game->px_block_y);
	mlx->img_collect = mlx_xpm_file_to_image(mlx->mlx_init,
			COLLECT, &game->px_block_x, &game->px_block_y);
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_init,
			PLAYER, &game->px_block_x, &game->px_block_y);
	mlx->img_exit = mlx_xpm_file_to_image(mlx->mlx_init,
			EXIT_B, &game->px_block_x, &game->px_block_y);
	mlx->img_mob = mlx_xpm_file_to_image(mlx->mlx_init,
			TRAP, &game->px_block_x, &game->px_block_y);
	draw_map(mlx, game, data);
	mlx->cpy_game = game;
	mlx->cpy_map = data;
	move_counter(mlx);
	player_control(data, mlx, game);
	mlx_loop_hook(mlx->mlx_init, &trap_animation, mlx);
	mlx_loop(mlx->mlx_init);
}
