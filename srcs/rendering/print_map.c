/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/20 20:48:52 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

/**
 * Draws player as yellow square of size 8 and a small yellow ray in the direction player is oriented
*/
void	print_player(t_master *master, int color)
{
	int	i;
	int j;
	int	p_size;

	p_size = 8;
	p_size /= 2;
	i = - p_size;
	while (i < p_size)
	{
		j = - p_size;
		while (j < p_size)
		{
			img_pix_put(&master->mlx.img, master->player.px + i, master->player.py + j, color);
			j++;
		} 
		i++;
	}
	draw_line(master, master->player.px, master->player.py, master->player.px + 20 * master->player.pdx, master->player.py + 20 * master->player.pdy, color);
}

static void	print_square(t_master *master, int x, int y, int color)
{
	int	i;
	int j;

	i = 0;
	while (i < BLOCK - 1)
	{
		j = 0;
		while (j < BLOCK - 1)
		{
			img_pix_put(&master->mlx.img, x + i, y + j, color);
			j++;
		} 
		i++;
	}
}

static void	print_background(t_master *master)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(&master->mlx.img, j, i, GRAY_PIXEL);
			j++;
		} 
		i++;
	}
	
}

void	print_init_map(t_master *master)
{
	int map[] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 0, 0,
		1, 0, 1, 0, 1, 1, 0, 0,
		1, 0, 0, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	
	master->map.nb_cols = 8;
	master->map.nb_rows = 8;
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.block_size = 64;
	master->map.map_arr = ft_calloc(master->map.nb_blocks, sizeof(int));
	ft_memcpy(master->map.map_arr, map, master->map.nb_blocks * sizeof(int));
	print_background(master);
}