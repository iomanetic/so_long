/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:55:12 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 19:41:25 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../src/gnl/get_next_line.h"
# include "defines.h"
# include "structs.h"

# ifndef FUNCTIONS

int			ft_strncmp(const char *s1, const char *s2);
int			check_file_name(char *ag);
void		check_valid(char *ag, int ac);
void		error_file_name(void);
void		non_valid_numbers_arg(void);
void		map_non_valid(void);
char		**map_init(char *ag, t_map *data);
void		free_data(t_map *data);
void		map_validation(t_map *data);
char		**ft_split(char const *s, char c);
int			ft_strnchr(const char *s, int c);
void		draw_window(t_mlx *mlx, t_map *data, t_game_info *game);
void		draw_map(t_mlx *mlx, t_game_info *game, t_map *data);
void		draw_block(char *line, t_mlx *mlx, t_game_info *game, int y_map);
void		player_control(t_map *data, t_mlx *mlx, t_game_info *game);
void		validation_error(t_map *data);
void		w_control(t_mlx *mlx);
void		s_control(t_mlx *mlx);
void		d_control(t_mlx *mlx);
void		a_control(t_mlx *mlx);
int			esc_control(t_mlx *cpyStruct);
void		trap_control(t_mlx *mlx, char keycode);
void		ft_exit_game(t_mlx *mlx);
void		ft_exit_loose(t_mlx *mlx);
char		*ft_itoa(int n);
void		move_counter(t_mlx *mlx);
int			trap_animation(t_mlx *mlx);
# endif

#endif