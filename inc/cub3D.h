/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:30:20 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 16:23:38 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "stdio.h"
# include <mlx.h>

// -------- Game Settings --------
# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 512
# define SCALE 64
# define PLAYER_SIZE 5
# define ANGLE_VIEW 60
# define PLAYER_SPEED 10
# define ANGLE_SPEED 5

// -------- Minimap settings --------
# define MINIMAP_OFF 10
# define MINIMAP_SIZE 100

// -------- Colors --------
# define RED_PIXEL 0x9E1A1A
# define DARK_RED_PIXEL 0xB53737
# define BLACK_PIXEL 0x000000
# define WHITE_PIXEL 0xFFFFFF
# define GRAY_PIXEL 0x808080
# define YELLOW_PIXEL 0xFFFF00
# define BLUE_PIXEL 0x63C5DA
# define GREEN_PIXEL 0x028A0F

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_player
{
	float	px;
	float	py;
	int		pa;
	float	pdx;
	float	pdy;
}	t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
} t_mlx;

typedef struct s_map
{
	int			nb_cols;
	int			nb_rows;
	int			nb_blocks;
	int			block_size;
	int			map_s;
	float		ra;
	float		disT;
	float		rx;
	float		ry;
	float		rx_f;
	float		ry_f;
	char		f;
	int			dof;
	int			color;
	int			ceil_col;
	int			floor_col;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
} t_map;

typedef struct s_master
{
	t_map		map;
	t_player 	player;
	t_mlx		mlx;
}	t_master;

#endif