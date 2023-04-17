/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/17 16:30:16 by arebelo          ###   ########.fr       */
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
	float	disT;

	ra = master->player.pa - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r++ < 60)
	{
		//------------Check horizontal lines------------
		float	aTan = -1 /tan(ra);
		float	distH;
		float	hx;
		float	hy;
		
		dof = 0;
		distH = 0;
		
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
			if ((mp >= 0 && mp < 8 * 8 && master->map[mp] == 1) || dof == 7)	// Hit a wall
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

			if ((mp > 0 && mp < 8 * 8 && master->map[mp] == 1) || dof == 7)	// Hit a wall  @arebelo because there are 8 columns
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
				if (rx < 0 && ry < 0)
					dof = 7;
			}
		}
		int color;
		if (distH < distV)
		{
			draw_line(master, master->player.px, master->player.py, hx, hy, create_trgb(255, 255, 0, 0));
			color = create_trgb(255, 255, 0, 0);
			disT = distH;
		}
		else
		{
			draw_line(master, master->player.px, master->player.py, vx, vy, create_trgb(255, 225, 0, 0));
			color = create_trgb(255, 225, 0, 0);
			disT = distV;
		}

		//-------------- Draw 3D Walls ------------
		int	lineH;
		float ca = master->player.pa - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca);
		lineH = (64 * 320) / disT;			// Line height
		if (lineH > 320)
			lineH = 320;
		int lineOff = 160 - lineH / 2;
		if (lineOff > 320)
			lineOff = 320;
		int	aaa = lineOff + lineH;
		if (aaa < 0)
		{
			aaa = 64;
		}
		draw_line(master, r * 8 +530, lineOff, r * 8 + 530, aaa, color);
		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}
			// printf("Got here! <%d>\n", aaa);
		// printf("Begin(%d, %d)    End(%d, %d)\n", r * 8 +530, lineOff, r * 8 + 530, aaa);
		// printf("Horizonatl line\n");
		// printf("Vertical line\n");
		// printf("player(%f, %f) -------- point(%f, %f)\n", master->player.px + 4, master->player.py + 4, vx, vy);
		// printf("ra %f | Tan %f\n", ra, tan(ra));
		// printf("testing up rx: %f   ry: %f\n", rx, ry);
		// printf("testing down rx: %f   ry: %f\n", rx, ry);
		// printf("mx: %d ---- my: %d ---- mp: %d\n", mx, my, mp);