/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:34:11 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 15:08:59 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// void	pars_keycode(int keycode, t_mlx *mlx, t_map *data, t_game_info *game)

int	keycode(int keycode, t_mlx *mlx)
{
	if (mlx->cpy_game->score_game == 2147483647)
		mlx->cpy_game->score_game = 0;
	if (keycode == 13)
		w_control(mlx);
	if (keycode == 1)
		s_control(mlx);
	if (keycode == 2)
		d_control(mlx);
	if (keycode == 0)
		a_control(mlx);
	if (keycode == 53)
		esc_control(mlx);
	return (0);
}

void	player_control(t_map *data, t_mlx *mlx, t_game_info *game)
{
	mlx->cpy_map = data;
	mlx->cpy_game = game;
	mlx_key_hook(mlx->mlx_win, keycode, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, esc_control, mlx);
}
