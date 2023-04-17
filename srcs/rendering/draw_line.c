/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:10:02 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/17 15:53:41 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

// void draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double deltaX = endX - beginX;
// 	double deltaY = endY - beginY;
// 	double minX;
// 	double maxX;
// 	double pixelY;

// 	if (beginX < endX)
// 	{
// 		minX = beginX;
// 		maxX = endX;
// 	}
// 	else
// 	{
// 		minX = endX;
// 		maxX = beginX;
// 	}
// 	while (minX <= maxX)
// 	{
// 		pixelY = beginY + (deltaY * (minX - beginX) / deltaX);
// 		if (minX >= 0 && pixelY >= 0 && minX <= WINDOW_WIDTH && pixelY <= WINDOW_HEIGHT) 
// 			img_pix_put(&master->mlx.img, minX, pixelY, color);
// 		minX++;
// 	}	
// }

void draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color)
{
	double		deltaX = endX - beginX;
	double 		deltaY = endY - beginY;
	int			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	double		pixelX = beginX;
	double		pixelY = beginY;

	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		if (pixelX >= 0 && pixelY >= 0 && pixelX <= WINDOW_WIDTH && pixelY <= WINDOW_HEIGHT)
			img_pix_put(&master->mlx.img, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}
