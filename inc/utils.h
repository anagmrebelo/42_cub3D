/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:18:27 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 12:18:38 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3D.h"

// colors.c
int		img_pix_get(t_img *img, int x, int y);
void	draw_pixel(t_master *master, int x, int y, int color);
float	calc_distance(t_master *master);
int		create_trgb(int t, int r, int g, int b);

// angles.c
float	deg_to_rad(float d);
float	angle_check(float ang);
float	ft_abs_float(float n);
int		ft_abs(int n);

char	*join_free_s1(char *s1, char *s2);
char	*join_double_free(char *s1, char *s2);

#endif