/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:14:01 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 15:08:48 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_exit_loose(t_mlx *mlx)
{
	printf("\nYou loose!Try again please.\n");
	free_data(mlx->cpy_map);
	free(mlx);
	free(mlx->cpy_game);
	exit(0);
}

void	trap_control(t_mlx *mlx, char keycode)
{
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player + 1] == 'M' && keycode == 'D')
		ft_exit_loose(mlx);
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] == 'M' && keycode == 'A')
		ft_exit_loose(mlx);
	if (mlx->cpy_map->map[mlx->cpy_map->y_player - 1]
		[mlx->cpy_map->x_player] == 'M' && keycode == 'W')
		ft_exit_loose(mlx);
	if (mlx->cpy_map->map[mlx->cpy_map->y_player + 1]
		[mlx->cpy_map->x_player] == 'M' && keycode == 'S')
		ft_exit_loose(mlx);
}
