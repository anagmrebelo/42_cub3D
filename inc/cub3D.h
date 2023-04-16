/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:30:20 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 20:18:41 by anarebelo        ###   ########.fr       */
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

# define BLOCK 64
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 512
# define PLAYER_SIZE 8

#define RED_PIXEL 0xFF0000
#define BLACK_PIXEL 0x000000
#define WHITE_PIXEL 0xFFFFFF
#define GRAY_PIXEL 0x808080
#define YELLOW_PIXEL 0xFFFF00

#define GRID_SIZE 1

#define PI 3.1415926
#define P2 PI/2
#define P3 3 * PI/2

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
	float 	pa;
	float	pdx;
	float 	pdy;
}	t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
} t_mlx;

typedef struct s_master
{
	int 		*map;
	t_player 	player;
	t_mlx		mlx;
}	t_master;

void	print_player(t_master *master, int color);

#endif