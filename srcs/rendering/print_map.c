/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/17 16:10:08 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	print_player(t_master *master, int color)
{
	int	i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			img_pix_put(&master->mlx.img, master->player.px + i, master->player.py + j, color);
			j++;
		} 
		i++;
	}
	draw_line(master, master->player.px, master->player.py, master->player.px + 5* master->player.pdx, master->player.py + 5* master->player.pdy, color);
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
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	int	i;
	int	j;
	int counter;

	master->map = ft_calloc(64, sizeof(int));
	ft_memcpy(master->map, map, 64 * sizeof(int));
	print_background(master);
	i = 0;
	j = 0;
	counter = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (map[counter] == 0)
				print_square(master, j * BLOCK, i * BLOCK, BLACK_PIXEL);
			else if (map[counter] == 1)
				print_square(master, j * BLOCK , i * BLOCK, WHITE_PIXEL);
			j++;
			counter++;
		}
		i++;	
	}
}