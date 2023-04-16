/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:18:27 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 20:28:41 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "cub3D.h"

int		create_trgb(int t, int r, int g, int b);
void	img_pix_put(t_img *img, int x, int y, int color);
void 	draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color);
float	calc_distance(t_master *master, int beginX, int beginY, int endX, int endY);

#endif