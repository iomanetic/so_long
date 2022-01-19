/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:57:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 16:50:29 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char		**map;
	int			player;
	int			collect;
	int			exit;
	int			x_player;
	int			y_player;
	int			x_map;
	int			y_map;
}				t_map;

typedef struct s_gameInfo
{
	int			px_block_x;
	int			px_block_y;
	int			size_map_x;
	int			size_map_y;
	int			score_game;
}				t_game_info;

typedef struct s_mlx
{
	void		*mlx_init;
	void		*mlx_win;
	void		*img_wall;
	void		*img_player;
	void		*img_floor;
	void		*img_collect;
	void		*img_exit;
	void		*img_mob;
	void		*img_trap_lower;
	t_map		*cpy_map;
	t_game_info	*cpy_game;
}				t_mlx;
#endif