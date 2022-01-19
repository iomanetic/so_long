/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_counter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:12 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 15:08:35 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_counter(t_mlx *mlx)
{
	char	*counter;
	int		tmp_x_map;

	tmp_x_map = mlx->cpy_map->x_map;
	counter = ft_itoa(mlx->cpy_game->score_game);
	while (tmp_x_map--)
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win,
			mlx->img_floor, tmp_x_map * 32, mlx->cpy_game->size_map_y - 32);
	mlx_string_put(mlx->mlx_init, mlx->mlx_win, 5,
		mlx->cpy_game->size_map_y - 32, 0x333300, "COUNTER:");
	mlx_string_put(mlx->mlx_init, mlx->mlx_win, 90,
		mlx->cpy_game->size_map_y - 32, 0x333300, counter);
	free(counter);
}
