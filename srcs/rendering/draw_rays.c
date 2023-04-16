/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 23:55:29 by anarebelo        ###   ########.fr       */
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
	while (r++ < 1)
	{
		//------------Check horizontal lines------------
		float	aTan = -1 /tan(ra);
		float	distH;
		float	hx;
		float	hy;
		
		dof = 0;
		distH = 0;
		
		printf("ra %f | Tan %f\n", ra, tan(ra));
		if (ra > PI) //Looking up
		{
			ry = (((int) master->player.py >> 6) << 6) - 0.0001;
			rx = (master->player.py - ry) * aTan + master->player.px;
			printf("testing up rx: %f   ry: %f\n", rx, ry);
			yo = -BLOCK;
			xo = -yo * aTan;
		}
		if (ra < PI)	//Looking down
		{
			ry = (((int) master->player.py >> 6) << 6) + BLOCK;
			rx = (master->player.py - ry) * aTan + master->player.px;
			printf("testing down rx: %f   ry: %f\n", rx, ry);
			yo = BLOCK;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)	//Looking straight left or right
		{
			hx = master->player.px;
			hy = master->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * 8 + mx;		//8 is the number of columns
			printf("mx: %d ---- my: %d ---- mp: %d\n", mx, my, mp);

			if (mp >= 0 && mp < 8 * 8 && master->map[mp] == 1)	// Hit a wall
			{
				distH = calc_distance(master, master->player.px, master->player.py, rx, ry);
				hx = rx;
				hy = ry;
				dof = 8;
			}
			else if (dof == 7)
			{
				distH = calc_distance(master, master->player.px, master->player.py, rx, ry);
				hx = rx;
				hy = ry;
				dof = 8;
			}
			else 		// next horizontal line 
			{
				rx += xo;
				ry += yo;
				dof +=1;
			}
		}
		//------------Check vertical lines------------
		float nTan = -tan(ra);
		float	distV;
		float	vx;
		float	vy;

		dof = 0;
		distV = 0;
		if (ra > P2 && ra < P3) 	//Looking left
		{
			rx = (((int) master->player.px >> 6) << 6) - 0.0001;
			ry = (master->player.px - rx) * nTan + master->player.py;
			xo = -BLOCK;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3)	//Looking right
		{
			rx = (((int) master->player.px >> 6) << 6) + BLOCK;
			ry = (master->player.px - rx) * nTan + master->player.py;
			xo = BLOCK;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == PI) //Looking straight up or down
		{
			vx = master->player.px;
			vy = master->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * 8 + mx;		//8 is the number of columns

			if (mp > 0 && mp < 8 * 8 && master->map[mp] == 1)	// Hit a wall
			{
				distV = calc_distance(master, master->player.px, master->player.py, rx, ry);
				vx = rx;
				vy = ry;
				dof = 8;
			}
			else if (dof == 7)
			{
				distV = calc_distance(master, master->player.px, master->player.py, rx, ry);
				vx = rx;
				vy = ry;
				dof = 8;
			}
			else 		// next horizontal line 
			{
				rx += xo;
				ry += yo;
				dof +=1;
			}
		}
		if (distH < distV)
		{
			printf("Horizonatl line\n");
			printf("player(%f, %f) -------- point(%f, %f)\n", master->player.px + 4, master->player.py + 4, hx, hy);
			draw_line(master, master->player.px + 4, master->player.py + 4, hx, hy, RED_PIXEL);
		}
		else
		{
			printf("Vertical line\n");
			printf("player(%f, %f) -------- point(%f, %f)\n", master->player.px + 4, master->player.py + 4, vx, vy);
			draw_line(master, master->player.px + 4, master->player.py + 4, vx, vy, RED_PIXEL);
		}
	}
}