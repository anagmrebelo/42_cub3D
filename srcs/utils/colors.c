/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/20 18:18:27 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

float	calc_distance(t_master *master)
{
	return (cos(deg_to_rad(master->map.ra)) * (master->map.rx - master->player.px) - sin(deg_to_rad(master->map.ra)) * (master->map.ry - master->player.py));
	// return (sqrt((endX - beginX) * (endX - beginX) + (endY - beginY) * (endY - beginY)));
}
