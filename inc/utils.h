/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:18:27 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/24 15:40:45 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "cub3D.h"

// colors.c
void	img_pix_put(t_img *img, int x, int y, int color);
int		img_pix_get(t_img *img, int x, int y);
void	draw_pixel(t_master *master, int x, int y, int color);
float	calc_distance(t_master *master);

// angles.c
float	deg_to_rad(float d);
float	angle_check(float ang);

#endif