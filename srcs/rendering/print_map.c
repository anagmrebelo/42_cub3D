/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/23 11:36:30 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	print_init_map(t_master *master)
{
	int map[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
	
	master->map.nb_cols = 11;
	master->map.nb_rows = 8;
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.map_arr = ft_calloc(master->map.nb_blocks, sizeof(int));
	master->map.block_size = SCALE;
	master->map.ceil_col = BLUE_PIXEL;
	master->map.floor_col = GREEN_PIXEL;
	ft_memcpy(master->map.map_arr, map, master->map.nb_blocks * sizeof(int));
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;
}