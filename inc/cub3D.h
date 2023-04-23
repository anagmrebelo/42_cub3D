/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:30:20 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/23 10:11:39 by anarebelo        ###   ########.fr       */
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

# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 512
# define SCALE 64
# define PLAYER_SIZE 5
# define ANGLE_VIEW 60

# define RED_PIXEL 0x9E1A1A
# define DARK_RED_PIXEL 0xB53737
# define BLACK_PIXEL 0x000000
# define WHITE_PIXEL 0xFFFFFF
# define GRAY_PIXEL 0x808080
# define YELLOW_PIXEL 0xFFFF00

# define MINIMAP_OFF 10
# define MINIMAP_SIZE 100


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
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
	int 		*map_arr;
	int			nb_cols;
	int			nb_rows;
	int			nb_blocks;
	int			block_size;
	int			map_s;
	float		ra;
	float		disT;
	float		rx;
	float		ry;
	int			dof;
	int			color;
} t_map;

typedef struct s_master
{
	t_map		map;
	t_player 	player;
	t_mlx		mlx;
}	t_master;

#endif