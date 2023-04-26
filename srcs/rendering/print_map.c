/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 17:31:29 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "free.h"

void	print_init_map(t_master *master)
{
	// Mica parsing
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.block_size = SCALE;
	master->map.ceil_col = create_trgb(0, master->map.color_c[0], master->map.color_c[1], master->map.color_c[0]);
	master->map.floor_col = create_trgb(0, master->map.color_f[0], master->map.color_f[1], master->map.color_f[0]);

	// Definining minimap scale
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;
}
