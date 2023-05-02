/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/05/02 10:46:16 by arebelo          ###   ########.fr       */
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
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.block_size = SCALE;
	master->map.ceil_col = create_trgb(0, master->map.color_c[0],
			master->map.color_c[1], master->map.color_c[2]);
	master->map.floor_col = create_trgb(0, master->map.color_f[0],
			master->map.color_f[1], master->map.color_f[2]);
	// Definining minimap scale
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;
}

/**
 * Define line height to be drawn on screen and offset to center of the screen
*/
void	update_dis_t(t_master *master, t_img text)
{
	float	ca;

	ca = angle_check(master->player.pa - master->map.ra);
	master->map.dis_t = master->map.dis_t * cos(deg_to_rad(ca));
	master->map.dis_t = (master->map.block_size * WINDOW_HEIGHT)
		/ master->map.dis_t;
	master->map.ty_step = text.height / master->map.dis_t;
	master->map.ty_off = 0;
	if (master->map.dis_t > WINDOW_HEIGHT)
	{
		master->map.ty_off = (master->map.dis_t - WINDOW_HEIGHT) / 2.0;
		master->map.dis_t = WINDOW_HEIGHT;
	}
	master->map.line_off = WINDOW_HEIGHT / 2 - master->map.dis_t / 2;
	master->map.line_f = master->map.dis_t + master->map.line_off ;
}

/**
 * Returns the texture according to ray angle
*/
t_img	find_texture(t_master *master)
{
	t_img	ret;

	if (master->map.f == 'h' && master->map.ra < 180)
		ret = master->map.north;
	else if (master->map.f == 'h' && master->map.ra >= 180)
		ret = master->map.south;
	else if (master->map.f == 'v' && master->map.ra > 90
		&& master->map.ra < 270)
		ret = master->map.west;
	else
		ret = master->map.east;
	return (ret);
}
