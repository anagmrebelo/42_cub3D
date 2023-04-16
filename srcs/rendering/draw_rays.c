/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 19:56:54 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_rays_3D(t_master *master)
{
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	int		r;		//number of rays to draw
	int		dof;
	int		mx;
	int		my;
	int		mp;

	ra = master->player.pa;
	r = 0;
	dof = 0;
	while (r++ < 1)
	{
		//-----Check horizontal lines-----
		float aTan = -1 /tan(ra);
		// printf("ra %f | Tan %f\n", ra, tan(ra));
		if (ra > PI) //Looking up
		{
			ry = (((int) master->player.py >> 6) << 6) - 0.0001;
			rx = (master->player.py - ry) * aTan + master->player.px;
			yo = -BLOCK;
			xo = -yo * aTan;
		}
		if (ra < PI)	//Looking down
		{
			ry = (((int) master->player.py >> 6) << 6) + BLOCK;
			rx = (master->player.py - ry) * aTan + master->player.px;
			yo = BLOCK;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = master->player.px;
			ry = master->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * 8 + mx;		//8 is the number of columns

			if (mp < 8 * 8 && master->map[mp] == 1)	// Hit a wall
				dof = 8;
			else 		// next horizontal line 
			{
				rx += xo;
				ry += yo;
				dof +=1;
			}
		}
		draw_line(master, master->player.px, master->player.py, rx, ry, RED_PIXEL);
	}
}