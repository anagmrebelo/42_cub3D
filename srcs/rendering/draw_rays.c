/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/20 20:03:40 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

/***
 * Prints in the image vertical line per ray
 * Offset to the center of the screen
 * Removed fish eye-effect
*/
static void	draw_3D_wall(t_master *master, int r, int color)
{
	float	line_h;
	float	ca;
	float	line_off;
	float	line_f;
	
	ca = angle_check(master->player.pa - master->map.ra);
	master->map.disT = master->map.disT * cos(deg_to_rad(ca));
	line_h = (master->map.block_size * WINDOW_HEIGHT) / master->map.disT;
	if (line_h > WINDOW_HEIGHT)
		line_h = WINDOW_HEIGHT;
	line_off = WINDOW_HEIGHT / 2 - line_h / 2;
	line_f = line_h + line_off;
	if (line_off > WINDOW_HEIGHT)
		line_off = WINDOW_HEIGHT;
	draw_line(master, r, line_off, r, line_f, color);
}

/**
 * Finds next line and saves distance to player in master->map.disT
*/
static void find_obs(t_master *master, float xo, float yo, int color)
{
	int		mx;
	int		my;
	int		mp;
	float	temp;
	
	mx = (int)(master->map.rx) >> 6;
	my = (int)(master->map.ry) >> 6;
	mp = my * master->map.nb_cols + mx;
	if ((mp >= 0 && mp < master->map.nb_blocks && master->map.map_arr[mp] == 1))	// Hit a wall
	{
		temp = calc_distance(master);
		if (temp < master->map.disT)
		{
			master->map.color = color;
			master->map.disT = temp;
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
		find_obs(master, xo, yo, DARK_RED_PIXEL);
}

/**
 * Finds next horizontal line and saves distance to player in master->map.disT
*/
static void find_obs_hor(t_master *master, float xo, float yo)
{	
	while (master->map.dof < master->map.nb_rows)
		find_obs(master, xo, yo, RED_PIXEL);
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
		master->map.rx = (((int)master->player.px >> 6) << 6) + master->map.block_size;
		master->map.ry = (master->player.px - master->map.rx) * tang + master->player.py;
		xo = master->map.block_size;
		yo = -xo * tang;
	}
	else if (master->map.ra > 90 && master->map.ra < 270)	//Looking Left
	{
		master->map.rx = (((int) master->player.px >> 6) << 6) - 0.0001;
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
		master->map.ry = (((int) master->player.py >> 6) << 6) - 0.0001;
		master->map.rx = (master->player.py - master->map.ry) * tang + master->player.px;
		yo = -master->map.block_size;
		xo = -yo * tang;
	}
	else if (master->map.ra > 180 && !isnan(tang))	//Looking down
	{
		master->map.ry = (((int) master->player.py >> 6) << 6) + master->map.block_size;
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
	while (r++ < WINDOW_WIDTH)
	{
		//------------ Check vertical lines------------
		check_vertical_lines(master);
		//------------ Check horizontal lines------------
		check_horizontal_lines(master);
		// ----------- Draw 3D Walls ------------
		draw_3D_wall(master, r, master->map.color);
		master->map.ra = angle_check(master->map.ra - (float)ANGLE_VIEW / WINDOW_WIDTH);
	}
}
