/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:10:02 by arebelo           #+#    #+#             */
/*   Updated: 2023/06/14 19:01:20 by mrollo           ###   ########.fr       */
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
	if (ft_abs(point_b[0] - point_a[0]) > ft_abs(point_b[1] - point_a[1]))
		steps = ft_abs(point_b[0] - point_a[0]);
	else
		steps = ft_abs(point_b[1] - point_a[1]);
	x_inc = (point_b[0] - point_a[0]) / (float)steps;
	y_inc = (point_b[1] - point_a[1]) / (float)steps;
	i = 0;
	while (i <= steps)
	{
		draw_pixel(master, round(point_a[0]), round(point_a[1]), color);
		point_a[0] += x_inc;
		point_a[1] += y_inc;
		i++;
	}
}
