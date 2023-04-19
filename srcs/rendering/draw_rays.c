/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/19 18:55:10 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_rays_3D(t_master *master)
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	ra;

	int		r;		//number of rays to draw
	int		mx;
	int		my;
	int		mp;
	int		dof;

	float	distT;

	ra = angle_check(master->player.pa + 30);
	// printf("Ray angle %f\n", ra);
	r = 0;
	while (r++ < 960)
	{
		//------------Check vertical lines------------
		float 	tang = tan(deg_to_rad(ra));
		float	distV;
		float	vx;
		float	vy;

		dof = 0;
		distV = 100000;
		
		if (ra < 90 || ra > 270) 	//Looking Right
		{
			rx = (((int)master->player.px >> 6) << 6) + master->map.block_size;
			ry = (master->player.px - rx) * tang + master->player.py;
			xo = master->map.block_size;
			yo = -xo * tang;
		}
		else if (ra > 90 && ra < 270)	//Looking Left
		{
			rx = (((int) master->player.px >> 6) << 6) - 0.0001;
			ry = (master->player.px - rx) * tang + master->player.py;
			xo = -master->map.block_size;
			yo = -xo * tang;
		}
		else //Looking straight up or down
		{
			rx = master->player.px;
			ry = master->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * master->map.nb_cols + mx;
			if ((mp >= 0 && mp < master->map.nb_blocks && master->map.map_arr[mp] == 1))	// Hit a wall  @arebelo
			{
				
				distV = cos(deg_to_rad(ra)) * (rx - master->player.px) - sin(deg_to_rad(ra)) * (ry - master->player.py);
				dof = 8;
			}
			else 		// next vertical line 
			{
				rx += xo;
				ry += yo;
				dof +=1;
			}
		}
		vx = rx;
		vy = ry;

		
		//------------Check horizontal lines------------
		tang = 1.0 /tan(deg_to_rad(ra));
		float	distH;

		dof = 0;
		distH = 100000;

		if (ra < 180 && ra > 0 && !isnan(tang)) //Looking up
		{
			ry = (((int) master->player.py >> 6) << 6) - 0.0001;
			rx = (master->player.py - ry) * tang + master->player.px;
			yo = -master->map.block_size;
			xo = -yo * tang;
		}
		else if (ra > 180 && !isnan(tang))	//Looking down
		{
			ry = (((int) master->player.py >> 6) << 6) + master->map.block_size;
			rx = (master->player.py - ry) * tang + master->player.px;
			yo = master->map.block_size;
			xo = -yo * tang;
		}
		else	//Looking straight left or right
		{
			rx = master->player.px;
			ry = master->player.py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * master->map.nb_rows + mx;
			if ((mp >= 0 && mp < master->map.nb_blocks && master->map.map_arr[mp] == 1))	// Hit a wall
			{
				distH = cos(deg_to_rad(ra)) * (rx - master->player.px) - sin(deg_to_rad(ra)) * (ry - master->player.py);
				dof = 8;
			}
			else 		// next horizontal line 
			{
				rx += xo;
				ry += yo;
				dof +=1;
			}
		}
		distT = distH;

		//------------Check shortest line------------
		int color;
		color = RED_PIXEL;
		if (distV < distH)
		{
			rx = vx;
			ry = vy;
			color = DARK_RED_PIXEL;
			distT = distV;
		}
		// draw_line(master, master->player.px, master->player.py, rx, ry, color);

		// -------------- Draw 3D Walls ------------
		int	lineH;
		float ca = angle_check(master->player.pa - ra);
		distT = distT * cos(deg_to_rad(ca));
		lineH = (master->map.block_size * WINDOW_HEIGHT) / distT;			// Line height
		if (lineH > WINDOW_HEIGHT)
			lineH = WINDOW_HEIGHT;
		int lineOff = WINDOW_HEIGHT / 2 - lineH / 2;						// To center the line
		int aaa = lineH + lineOff;
		if (aaa > WINDOW_HEIGHT)
			aaa = WINDOW_HEIGHT;
		draw_line(master, r, lineOff, r, lineH + lineOff, color);

		ra = angle_check(ra - 60.0/960.0);
	}
}



		// printf("FINAL (%f, %f) (%f, %f)\n", master->player.px, master->player.py, rx, ry);
		// printf("Got here! <%d>\n", r);
		// printf("Got here! <%d>\n", aaa);
		// printf("Begin(%d, %d)    End(%d, %d)\n", r * 8 +530, lineOff, r * 8 + 530, aaa);
		// printf("Horizonatl line\n");
		// printf("Vertical line\n");
		// printf("player(%f, %f) -------- point(%f, %f)\n", master->player.px + 4, master->player.py + 4, vx, vy);
		// printf("ra %f | Tan %f\n", ra, tan(ra));
		// printf("testing up rx: %f   ry: %f\n", rx, ry);
		// printf("testing down rx: %f   ry: %f\n", rx, ry);
		// printf("mx: %d ---- my: %d ---- mp: %d\n", mx, my, mp);
		// printf(" %f ra: %f, Horizontal (%f, %f) INT(%d, %d) -------- (%f, %f) INT(%d, %d)\n", P3, ra, master->player.px, master->player.py, (int)master->player.px, (int)master->player.py, hx, hy, (int)hx, (int)hy);
		// printf("ra: %f, Verical (%f, %f) INT(%d, %d) -------- (%f, %f) INT(%d, %d)\n", ra, master->player.px, master->player.py, (int)master->player.px, (int)master->player.py, vx, vy, (int)vx, (int)vy);