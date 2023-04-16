/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 20:28:51 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;
	double minX;
	double maxX;
	double pixelY;

	if (beginX < endX)
	{
		minX = beginX;
		maxX = endX;
	}
	else
	{
		minX = endX;
		maxX = beginX;
	}
	while (minX <= maxX)
	{
		pixelY = beginY + (deltaY * (minX - beginX) / deltaX);
		if (minX >= 0 && pixelY >= 0 && minX <= WINDOW_WIDTH && pixelY <= WINDOW_HEIGHT) 
			img_pix_put(&master->mlx.img, minX, pixelY, color);
		minX++;
	}	

}

float	calc_distance(t_master *master, int beginX, int beginY, int endX, int endY)
{
	(void) master;
	return (sqrt((endX - beginX) * (endX - beginX) + (endY - beginY) * (endY - beginY)));
}