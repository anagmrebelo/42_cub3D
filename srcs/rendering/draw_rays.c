/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/05/02 10:51:29 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

/**
 * Draws ceiling and floor lines according to colors given in map
*/
static void	draw_floor_ceil(t_master *master, int r)
{
	int		point_a[2];
	int		point_b[2];

	point_a[0] = r;
	point_a[1] = round(master->map.line_f);
	point_b[0] = r;
	point_b[1] = WINDOW_HEIGHT;
	// Draw floor
	draw_line(master, point_a, point_b, master->map.floor_col);
	point_a[1] = 0;
	point_b[1] = master->map.line_off;
	// Draw celing
	draw_line(master, point_a, point_b, master->map.ceil_col);
}

/**
 * Returns x depending if it is vertical or horizontal line
*/
static float	calc_tx(t_master *master, t_img text)
{
	float	tx;

	if (master->map.f == 'h')
	{
		tx = (int)(master->map.rx_f) % text.width;
		if (master->map.ra > 180)
			tx = text.width - 1 - tx;
	}
	else
	{
		tx = (int)(master->map.ry_f) % text.width;
		if (master->map.ra > 90 && master->map.ra < 270)
			tx = text.width - 1 - tx;
	}
	return (tx);
}

/***
 * Prints in the image vertical line per ray
 * Offset to the center of the screen
 * Removed fish eye-effect
*/
static void	draw_3d_wall(t_master *master, int r)
{
	t_img	text;
	float	y;
	float	ty;
	float	tx;

	text = find_texture(master);
	update_dis_t(master, text);
	y = 0;
	ty = master->map.ty_off * master->map.ty_step;
	tx = calc_tx(master, text);
	while (y < master->map.dis_t)
	{
		draw_pixel(master, r, y + master->map.line_off,
			img_pix_get(&text, (int)(tx), (int)(ty)));
		ty += master->map.ty_step;
		y++;
	}
	draw_floor_ceil(master, r);
}

/**
 * Finds next line and saves distance to player in master->map.dis_t
*/
void	find_obs(t_master *master, float xo, float yo, char c)
{
	int		mx;
	int		my;
	float	temp;

	mx = (int)(master->map.rx / SCALE);
	my = (int)(master->map.ry / SCALE);
	if (mx >= 0 && my >= 0 && mx < master->map.nb_cols
		&& my < master->map.nb_rows && master->map.mtx[my][mx] == '1')
	{
		temp = calc_distance(master);
		if (temp < master->map.dis_t)
		{
			master->map.dis_t = temp;
			master->map.f = c;
			master->map.rx_f = master->map.rx;
			master->map.ry_f = master->map.ry;
		}
		master->map.dof = INT_MAX;
	}
	else
	{
		master->map.rx += xo;
		master->map.ry += yo;
		master->map.dof += 1;
	}
}

/**
 * Draws one line per pixel according to wall distance to player
*/
void	draw_rays_3d(t_master *master)
{
	int		r;
	//number of rays to draw
	master->map.ra = angle_check(master->player.pa + ANGLE_VIEW / 2);
	r = 0;
	while (r < WINDOW_WIDTH)
	{
		master->map.dis_t = 100000;
		//------------ Check vertical lines------------
		check_vertical_lines(master);
		//------------ Check horizontal lines------------
		check_horizontal_lines(master);
		// ----------- Draw 3D Walls, ceilings and floors ------------
		draw_3d_wall(master, r);
		master->map.ra = angle_check(master->map.ra
				- (float)ANGLE_VIEW / WINDOW_WIDTH);
		r++;
	}
}
