/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:10:02 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/18 18:20:04 by arebelo          ###   ########.fr       */
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

// void draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double		deltaX = endX - beginX;
// 	double 		deltaY = endY - beginY;
// 	int			pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	double		pixelX = beginX;
// 	double		pixelY = beginY;

// 	deltaX /= pixels;
// 	deltaY /= pixels;
// 	while (pixels)
// 	{
// 		if (pixelX >= 0 && pixelY >= 0 && pixelX <= WINDOW_WIDTH && pixelY <= WINDOW_HEIGHT)
// 			img_pix_put(&master->mlx.img, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// }

static int ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * (-1));
}

void draw_line(t_master *master, int X0, int Y0, int X1, int Y1, int color)
{
	// calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float	X = X0;
    float	Y = Y0;
	int		i = 0;
	while (i <= steps)
	{
		if (X >= 0 && Y >= 0 && X <= WINDOW_WIDTH && Y <= WINDOW_HEIGHT)
        	img_pix_put(&master->mlx.img, round(X), round(Y), color);
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
		i++;
	}
    for (int i = 0; i <= steps; i++) {		//@remove for
		
    }
}
