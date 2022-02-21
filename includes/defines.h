/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:47:09 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/19 18:11:53 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef COLORS
#  define COLORS
#  define YELLOW "\033[0;33m"
# endif

# ifndef ERROR_MESSAGES
#  define ERROR_MESSAGES
#  define NVF "please remake name in *.ber\n"
#  define NVA "non valid numbers params\n"
#  define MNV "map non valid, please recheck\n"
#  define ERF "error read file\n"
# endif

# ifndef PATH_IMAGES
#  define PATH_IMAGES
#  define WALL "/images/wall.xpm"
#  define FLOOR "/images/floor.xpm"
#  define COLLECT "/images/collect.xpm"
#  define PLAYER "/images/player.xpm"
#  define EXIT "/images/exit.xpm"
# endif

# ifndef PATH_IMAGES_BONUS
#  define PATH_IMAGES_BONUS
#  define FLOOR_B "../images/bonus/floor_bonus.xpm"
#  define WALL_B "../images/bonus/wall_bonus.xpm"
#  define EXIT_B "../images/bonus/exit_bonus.xpm"
#  define TRAP "../images/bonus/trap_bonus.xpm"
#  define TRAP_A "../images/bonus/trap_lower.xpm"
# endif

#endif
