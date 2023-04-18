/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:18:27 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/18 19:37:56 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "cub3D.h"

// colors.c
void	img_pix_put(t_img *img, int x, int y, int color);
float	calc_distance(int beginX, int beginY, int endX, int endY);

// angles.c
float	deg_to_rad(int d);
int		angle_check(int ang);

#endif