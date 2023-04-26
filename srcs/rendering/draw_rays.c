/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 23:52:45 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

/***
 * Prints in the image vertical line per ray
 * Offset to the center of the screen
 * Removed fish eye-effect
*/
static void	draw_3D_wall(t_master *master, int r)
{
	float	line_h;
	float	ca;
	float	line_off;
	float	line_f;
	
	ca = angle_check(master->player.pa - master->map.ra);
	master->map.disT = master->map.disT * cos(deg_to_rad(ca));
	line_h = (master->map.block_size * WINDOW_HEIGHT) / master->map.disT;

	t_img	text;
	if (master->map.f == 'h' && master->map.ra < 180)
		text = master->map.north;
	else if (master->map.f == 'h' && master->map.ra >= 180)
		text = master->map.south;
	else if (master->map.f == 'v' && master->map.ra > 90 && master->map.ra < 270)
		text = master->map.west;
	else
		text = master->map.east;
	float	ty_step = text.height / line_h;
	float	ty_off = 0;
	if (line_h > WINDOW_HEIGHT)
	{
		ty_off = (line_h - WINDOW_HEIGHT) / 2.0;
		line_h = WINDOW_HEIGHT;
	}
	line_off = WINDOW_HEIGHT / 2 - line_h / 2;
	line_f = line_h + line_off;

	float y = 0;
	float ty = ty_off * ty_step;
	float tx;
	
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
	while (y < line_h)
	{
		int color = img_pix_get(&text, (int)(tx), (int)(ty));
		draw_pixel(master, r, y + line_off, color);
		ty += ty_step;
		y++;
	}
	// Draw floor
	draw_line(master, r, round(line_f), r, WINDOW_HEIGHT, master->map.floor_col);
	// Draw celing
	draw_line(master, r, 0, r, line_off, master->map.ceil_col);
}

/**
 * Finds next line and saves distance to player in master->map.disT
*/
static void find_obs(t_master *master, float xo, float yo, char c)
{
	int		mx;
	int		my;
	float	temp;
	
	mx = (int)(master->map.rx / SCALE);
	my = (int)(master->map.ry / SCALE);
	if (mx >= 0 && my >= 0 && mx < master->map.nb_cols && my < master->map.nb_rows && master->map.mtx[my][mx] == '1')	// Hit a wall
	{
		temp = calc_distance(master);
		if (temp < master->map.disT)
		{
			master->map.disT = temp;
			master->map.f = c;
			master->map.rx_f = master->map.rx;
			master->map.ry_f = master->map.ry;
		}
		master->map.dof = INT_MAX;
	} 
	else 		// next vertical line 
	{
		master->map.rx += xo;
		master->map.ry += yo;
		master->map.dof +=1;
	}
}

/**
 * Finds next vertical line and saves distance to player in master->map.disT
*/
static void find_obs_vert(t_master *master, float xo, float yo)
{	
	while (master->map.dof < master->map.nb_cols)
		find_obs(master, xo, yo, 'v');
}

/**
 * Finds next horizontal line and saves distance to player in master->map.disT
*/
static void find_obs_hor(t_master *master, float xo, float yo)
{	
	while (master->map.dof < master->map.nb_rows)
		find_obs(master, xo, yo, 'h');
}

static void	check_vertical_lines(t_master *master)
{
	float	tang;
	float	xo;
	float	yo;

	master->map.dof = 0;
	tang = tan(deg_to_rad(master->map.ra));
	master->map.disT = 100000;
	if (master->map.ra < 90 || master->map.ra > 270) 	//Looking Right
	{
		master->map.rx = ((int)(master->player.px / SCALE) * SCALE) + master->map.block_size;
		master->map.ry = (master->player.px - master->map.rx) * tang + master->player.py;
		xo = master->map.block_size;
		yo = -xo * tang;
	}
	else if (master->map.ra > 90 && master->map.ra < 270)	//Looking Left
	{
		master->map.rx = ((int)(master->player.px / SCALE) * SCALE) - 0.0001;
		master->map.ry = (master->player.px - master->map.rx) * tang + master->player.py;
		xo = -master->map.block_size;
		yo = -xo * tang;
	}
	else //Looking straight up or down
	{
		master->map.rx = master->player.px;
		master->map.ry = master->player.py;
		return ;
	}
	find_obs_vert(master, xo, yo);
}

static void	check_horizontal_lines(t_master *master)
{
	float	tang;
	float	xo;
	float	yo;

	tang = 1.0 /tan(deg_to_rad(master->map.ra));
	master->map.dof = 0;
	if (master->map.ra < 180 && master->map.ra > 0 && !isnan(tang)) //Looking up
	{
		master->map.ry = ((int)(master->player.py / SCALE) * SCALE) - 0.0001;
		master->map.rx = (master->player.py - master->map.ry) * tang + master->player.px;
		yo = -master->map.block_size;
		xo = -yo * tang;
	}
	else if (master->map.ra > 180 && !isnan(tang))	//Looking down
	{
		master->map.ry = ((int)(master->player.py / SCALE) * SCALE) + master->map.block_size;
		master->map.rx = (master->player.py - master->map.ry) * tang + master->player.px;
		yo = master->map.block_size;
		xo = -yo * tang;
	}
	else	//Looking straight left or right
	{
		master->map.rx = master->player.px;
		master->map.ry = master->player.py;
		return ;
	}
	find_obs_hor(master, xo, yo);
}

/**
 * Draws one line per pixel according to wall distance to player
*/
void		draw_rays_3D(t_master *master)
{
	int		r;	//number of rays to draw

	master->map.ra = angle_check(master->player.pa + ANGLE_VIEW / 2);
	r = 0;
	while (r < WINDOW_WIDTH)
	{
		//------------ Check vertical lines------------
		check_vertical_lines(master);
		//------------ Check horizontal lines------------
		check_horizontal_lines(master);
		// ----------- Draw 3D Walls, ceilings and floors ------------
		draw_3D_wall(master, r);
		master->map.ra = angle_check(master->map.ra - (float)ANGLE_VIEW / WINDOW_WIDTH);
		r++;
	}
}
