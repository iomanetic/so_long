/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_control_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:07:06 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 15:41:38 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	a_exit(t_mlx *mlx)
{
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] == 'E')
	{
		if (mlx->cpy_map->collect == 0)
			ft_exit_game(mlx);
		return (1);
	}
	return (0);
}

int	a_collect(t_mlx *mlx)
{
	if (mlx->cpy_map->collect == 0)
		return (0);
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] == 'C')
	{
		mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] = '0';
		mlx->cpy_map->collect--;
		if (mlx->cpy_map->collect == 0)
			printf("Oh yeah!Now I can get out of here....\n");
		return (1);
	}
	return (0);
}

int	a_wall(t_mlx *mlx)
{
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] == '1')
		return (1);
	return (0);
}

int	a_floor(t_mlx *mlx)
{
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] == '0')
		return (1);
	if (mlx->cpy_map->map[mlx->cpy_map->y_player]
		[mlx->cpy_map->x_player - 1] == 'P')
		return (1);
	return (0);
}

void	a_control(t_mlx *mlx)
{
	if (a_exit(mlx))
		return ;
	if (a_collect(mlx))
	{
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_floor,
			mlx->cpy_map->x_player * 32, mlx->cpy_map->y_player * 32);
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_floor,
			(mlx->cpy_map->x_player - 1) * 32, mlx->cpy_map->y_player * 32);
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_player,
			(mlx->cpy_map->x_player - 1) * 32, mlx->cpy_map->y_player * 32);
	}
	if (a_floor(mlx))
	{
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_floor,
			mlx->cpy_map->x_player * 32, mlx->cpy_map->y_player * 32);
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_player,
			(mlx->cpy_map->x_player - 1) * 32, mlx->cpy_map->y_player * 32);
	}
	if (a_wall(mlx))
		return ;
	trap_control(mlx, 'A');
	mlx->cpy_game->score_game++;
	move_counter(mlx);
	printf("%d\n", mlx->cpy_game->score_game);
	mlx->cpy_map->x_player--;
}
