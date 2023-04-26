/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 16:19:48 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	img_pix_get(t_img *img, int x, int y)
{
	char    *pixel;

	// if (y * img->line_len + x * (img->bpp / 8) >= 32 * 64 * 64)
	// 	printf("Got here!\n");
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pixel);
}

void	draw_pixel(t_master *master, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x <= WINDOW_WIDTH && y <= WINDOW_HEIGHT)
		img_pix_put(&master->mlx.img, round(x), round(y), color);	
}

float	calc_distance(t_master *master)
{
	return (cos(deg_to_rad(master->map.ra)) * (master->map.rx - master->player.px) - sin(deg_to_rad(master->map.ra)) * (master->map.ry - master->player.py));
}
