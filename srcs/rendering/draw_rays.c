/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:58:53 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/18 22:49:04 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_rays_3D(t_master *master)
{
	float	rx;
	float	ry;
	int		ra;
	float	xo;
	float	yo;

	int		r;		//number of rays to draw
	int		mx;
	int		my;
	int		mp;
	int		dof;

	float	disT;

	// ra = angle_check(master->player.pa + 30);
	ra = master->player.pa;
	r = 0;
	while (r++ < 1)
	{
		//------------Check vertical lines------------
		float 	tang = tan(deg_to_rad(ra));
		float	distV;
		float	vx;
		float	vy;

		dof = 0;
		distV = 100000;
		
		printf("%d\n", ra);
		if (ra < 90 || ra > 270) 	//Looking left
		{
			rx = (((int)master->player.px >> 6) << 6) + master->map.block_size;
			ry = (master->player.px - rx) * tang + master->player.py;
			xo = master->map.block_size;
			yo = -xo * tang;
		}
		else if (ra > 90 && ra < 270)	//Looking right
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
			if ((mp > 0 && mp < master->map.nb_blocks && master->map.map_arr[mp] == 1) || dof == 7)	// Hit a wall  @arebelo
			{
				// distV = calc_distance(master->player.px, master->player.py, rx, ry);
				distV = cos(deg_to_rad(ra)) * (rx - master->player.px) - sin(deg_to_rad(ra)) * (ry - master->player.py);
				dof = 8;
			}
			else 		// next vertical line 
			{
				rx += xo;
				ry += yo;
				dof +=1;
				// if (rx < 0 && ry < 0)
				// 	dof = 7;
			}
		}
		vx = rx;
		vy = ry;
		
		//------------Check horizontal lines------------
		tang = 1.0 /tan(ra);
		float	distH;

		dof = 0;
		distH = 100000;

		if (ra < 180) //Looking up
		{
			rx = (master->player.py - ry) * tang + master->player.px;
			ry = (((int)master->player.py >> 6) << 6) - 0.0001;
			xo = -yo * tang;
			yo = -master->map.block_size;
		}
		else if (ra > 180)	//Looking down
		{
			rx = (master->player.py - ry) * tang + master->player.px;
			ry = (((int) master->player.py >> 6) << 6) + master->map.block_size;
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
			printf("MP = %d\n", mp);
			if ((mp >= 0 && mp < master->map.nb_blocks && master->map.map_arr[mp] == 1)) // || dof == 7)	// Hit a wall
			{
				// printf("Hit a wall %f %f\n", rx, ry);
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

		int color;
		color = RED_PIXEL;
		if (distV < distH)
		{
			rx = vx;
			ry = vy;
			color = DARK_RED_PIXEL;
			disT = distH;
		}
		draw_line(master, master->player.px, master->player.py, rx, ry, color);

		// //-------------- Draw 3D Walls ------------
		// int	lineH;
		// float ca = master->player.pa - ra;
		// if (ca < 0)
		// 	ca += 2 * PI;
		// if (ca > 2 * PI)
		// 	ca -= 2 * PI;
		// disT = disT * cos(ca);
		// lineH = (64 * 320) / disT;			// Line height
		// if (lineH > 320)
		// 	lineH = 320;
		// int lineOff = 160 - lineH / 2;
		// if (lineOff > 320)
		// 	lineOff = 320;
		// int	aaa = lineOff + lineH;
		// if (aaa < 0)
		// {
		// 	aaa = 64;
		// }
		// draw_line(master, r * 8 +530, lineOff, r * 8 + 530, aaa, color);


		ra = angle_check(ra - 1);
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
		// printf(" %f ra: %f, Horizontal (%f, %f) INT(%d, %d) -------- (%f, %f) INT(%d, %d)\n", P3, ra, master->player.px, master->player.py, (int)master->player.px, (int)master->player.py, hx, hy, (int)hx, (int)hy);
		// printf("ra: %f, Verical (%f, %f) INT(%d, %d) -------- (%f, %f) INT(%d, %d)\n", ra, master->player.px, master->player.py, (int)master->player.px, (int)master->player.py, vx, vy, (int)vx, (int)vy);