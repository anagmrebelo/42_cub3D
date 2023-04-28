/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:10:02 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/28 12:16:26 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "utils.h"

void	draw_line(t_master *master, int point_a[2], int point_b[2], int color)
{
	int		steps;
	float	x_inc;
	float	y_inc;
	int		i;

	if (point_a[0] == point_b[0] && point_a[1] == point_b[1])
		return ;
	// calculate steps required for generating pixels
	if (ft_abs(point_b[0] - point_a[0]) > ft_abs(point_b[1] - point_a[1]))
		steps = ft_abs(point_b[0] - point_a[0]);
	else
		steps = ft_abs(point_b[1] - point_a[1]);
	// calculate increment in x & y for each steps
	x_inc = (point_b[0] - point_a[0]) / (float)steps;
	y_inc = (point_b[1] - point_a[1]) / (float)steps;
	// Put pixel for each step
	i = 0;
	while (i <= steps)
	{
		if (point_a[0] >= 0 && point_a[1] >= 0
			&& point_a[0] < WINDOW_WIDTH && point_a[1] < WINDOW_HEIGHT)
			img_pix_put(&master->mlx.img, round(point_a[0]),
				round(point_a[1]), color);
		point_a[0] += x_inc; // increment in x at each step
		point_a[1] += y_inc; // increment in y at each step
		i++;
	}
}
