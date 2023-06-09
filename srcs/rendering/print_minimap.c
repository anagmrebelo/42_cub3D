/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:09:26 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 16:09:51 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "utils.h"
#include "rendering.h"

static void	print_dir_line(t_master *master, int color)
{
	int	point_a[2];
	int	point_b[2];

	point_a[0] = master->player.px / SCALE * master->map.map_s + MINIMAP_OFF;
	point_a[1] = master->player.py / SCALE * master->map.map_s + MINIMAP_OFF;
	point_b[0] = master->player.px / SCALE * master->map.map_s
		+ MINIMAP_OFF + 5 * master->player.pdx;
	point_b[1] = master->player.py / SCALE * master->map.map_s
		+ MINIMAP_OFF + 5 * master->player.pdy;
	draw_line(master, point_a, point_b, color);
}

/**
 * Draws player as yellow square of size 8
 * Draw a small yellow ray in the direction player is oriented
*/
static void	print_player(t_master *master, int color)
{
	int	i;
	int	j;
	int	p_size;

	p_size = PLAYER_SIZE / 2;
	i = -1 * p_size;
	while (i < p_size)
	{
		j = -1 * p_size;
		while (j < p_size)
		{
			draw_pixel(master,
				master->player.px / SCALE * master->map.map_s + i + MINIMAP_OFF,
				master->player.py / SCALE * master->map.map_s + j + MINIMAP_OFF,
				color);
			j++;
		}
		i++;
	}
	print_dir_line(master, color);
}

/**
 * Prints squares starting at (x, y) with size of master->map.map_s
*/
static void	print_square(t_master *master, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < master->map.map_s)
	{
		j = 0;
		while (j < master->map.map_s)
		{
			draw_pixel(master, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

/**
 * Draw to image black line around minimap
*/
static void	print_frontier(t_master *master, int color)
{
	int	i;
	int	j;

	i = -2;
	j = 0;
	while (++i < master->map.nb_rows * master->map.map_s + 1)
	{
		j = -1;
		while (j < master->map.nb_cols * master->map.map_s + 1)
		{
			if (i == -1 || i == master->map.nb_rows * master->map.map_s
				|| j == -1 || j == master->map.nb_cols * master->map.map_s)
				draw_pixel(master, MINIMAP_OFF + j,
					MINIMAP_OFF + i, color);
			j++;
		}	
	}
}

/**
 * Prints minimap offset MINIMAP_OFF of (0, 0)
 * Player and small line indicating its angle
*/
void	print_minimap(t_master *master)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < master->map.nb_rows)
	{
		j = 0;
		while (j < master->map.nb_cols)
		{
			if (master->map.mtx[i][j] == '1' || master->map.mtx[i][j] == ' ')
				print_square(master, j * master->map.map_s + MINIMAP_OFF,
					i * master->map.map_s + MINIMAP_OFF, WHITE_PIXEL);
			else
				print_square(master, j * master->map.map_s + MINIMAP_OFF,
					i * master->map.map_s + MINIMAP_OFF, BLACK_PIXEL);
			j++;
		}	
	}
	print_frontier(master, BLACK_PIXEL);
	print_player(master, RED_PIXEL);
}
