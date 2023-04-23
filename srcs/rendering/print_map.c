/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/23 10:44:18 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

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
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
	
	master->map.nb_cols = 11;
	master->map.nb_rows = 8;
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.map_arr = ft_calloc(master->map.nb_blocks, sizeof(int));
	master->map.block_size = SCALE;
	ft_memcpy(master->map.map_arr, map, master->map.nb_blocks * sizeof(int));
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;
	print_background(master);
}