/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 11:30:22 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "free.h"

void	print_init_map(t_master *master)
{
	// Mica parsing
	master->map.nb_cols = 3;
	master->map.nb_rows = 4;
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.map_arr = ft_calloc(master->map.nb_blocks, sizeof(int));
	if (!master->map.map_arr)
		clean_exit(master);
	master->map.block_size = SCALE;
	master->map.ceil_col = BLUE_PIXEL;
	master->map.floor_col = GREEN_PIXEL;
	master->map.map_arr[0] = 1;
	master->map.map_arr[1] = 1;
	master->map.map_arr[2] = 1;
	master->map.map_arr[3] = 1;
	master->map.map_arr[4] = 0;
	master->map.map_arr[5] = 1;
	master->map.map_arr[6] = 1;
	master->map.map_arr[7] = 0;
	master->map.map_arr[8] = 1;
	master->map.map_arr[9] = 1;
	master->map.map_arr[10] = 1;
	master->map.map_arr[11] = 1;

	// Definining minimap scale
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;
}
