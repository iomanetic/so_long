/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:32:26 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 18:11:06 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_img(t_mlx *mlx, int x_pos_trap, int y_pos_trap, int step)
{
	mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
		mlx->img_floor, x_pos_trap * 32, y_pos_trap * 32);
	if (step == 1)
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_mob, x_pos_trap * 32, y_pos_trap * 32);
	if (step == 2)
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_trap_lower, x_pos_trap * 32, y_pos_trap * 32);
}

void	replace_img(t_mlx *mlx, char *line, int y_pos_trap, int step)
{
	int	x_pos_trap;

	x_pos_trap = 0;
	while (line[x_pos_trap])
	{
		if (line[x_pos_trap] == 'M')
			put_img(mlx, x_pos_trap, y_pos_trap, step);
		x_pos_trap++;
	}
}

void	search_trap(t_mlx *mlx, int step)
{
	int	y_pos_trap;

	y_pos_trap = 0;
	while (mlx->cpy_map->map[y_pos_trap])
	{
		replace_img(mlx, mlx->cpy_map->map[y_pos_trap], y_pos_trap, step);
		y_pos_trap++;
	}
}

int	hold_time(void)
{
	static int	time = 0;
	static int	step = 0;

	time++;
	if (time == 25)
	{
		step++;
		time = 0;
		if (step > 2)
			step = 0;
	}
	return (step);
}

int	trap_animation(t_mlx *mlx)
{
	static int	step;

	step = hold_time();
	mlx->img_trap_lower = mlx_xpm_file_to_image(mlx->mlx_init,
			TRAP_A, &mlx->cpy_game->px_block_x, &mlx->cpy_game->px_block_y);
	if (step > 2)
		step = 0;
	if (step > 0)
		search_trap(mlx, step);
	return (0);
}
