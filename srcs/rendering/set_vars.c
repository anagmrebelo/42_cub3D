/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/27 14:47:03 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "free.h"

void	set_positions(t_master *master)
{
	// Initial player position
	master->player.px = master->map.px * SCALE + SCALE / 2;
	master->player.py = master->map.py * SCALE + SCALE / 2;
	if (master->map.view == 'N')
		master->player.pa = 90;
	else if (master->map.view == 'S')
		master->player.pa = 270;
	else if (master->map.view == 'W')
		master->player.pa = 180;
	else if (master->map.view == 'E')
		master->player.pa = 0;
	master->player.pdx = cos(deg_to_rad(master->player.pa));
	master->player.pdy = -sin(deg_to_rad(master->player.pa));

	// Mica parsing
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.block_size = SCALE;
	master->map.ceil_col = create_trgb(0, master->map.color_c[0], master->map.color_c[1], master->map.color_c[2]);
	master->map.floor_col = create_trgb(0, master->map.color_f[0], master->map.color_f[1], master->map.color_f[2]);
	// Definining minimap scale
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;
}
