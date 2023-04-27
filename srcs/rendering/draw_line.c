/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:10:02 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/27 18:55:01 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "utils.h"

void	draw_line(t_master *master, int x0, int y0, int x1, int y1, int color)
{
	int		steps;
	float	x_inc;
	float	y_inc;
	int		i;
	
	if (x0 == x1 && y0 == y1)
		return ; 
	// calculate steps required for generating pixels
	if (ft_abs(x1 - x0) > ft_abs(y1 - y0))
		steps = ft_abs(x1 - x0);
	else
		steps = ft_abs(y1 - y0);
	// calculate increment in x & y for each steps
	x_inc = (x1 - x0) / (float)steps;
	y_inc = (y1 - y0) / (float)steps;
	// Put pixel for each step
	i = 0;
	while (i <= steps)
	{
		if (x0 >= 0 && y0 >= 0 && x0 < WINDOW_WIDTH && y0 < WINDOW_HEIGHT)
			img_pix_put(&master->mlx.img, round(x0), round(y0), color);
		x0 += x_inc; // increment in x at each step
		y0 += y_inc; // increment in y at each step
		i++;
	}
}
