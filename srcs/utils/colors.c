/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 16:10:16 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * Changes pixel of given image to given color
*/
static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

/**
 * Returns color of pixel in pos(x,y)
*/
int	img_pix_get(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pixel);
}

/**
 * Changes pixel of game image to given color
 * Checks x and y are within window limits
*/
void	draw_pixel(t_master *master, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
		img_pix_put(&master->mlx.img, x, y, color);
}

/**
 * Returns distance between player and ray collision with walls
*/
float	calc_distance(t_master *master)
{
	return (cos(deg_to_rad(master->map.ra))
		* (master->map.rx - master->player.px)
		- sin(deg_to_rad(master->map.ra))
		* (master->map.ry - master->player.py));
}

/**
 * Creates int representing RGB
*/
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
