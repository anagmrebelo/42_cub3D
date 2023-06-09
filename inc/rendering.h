/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:33 by anarebelo         #+#    #+#             */
/*   Updated: 2023/05/02 10:14:52 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3D.h"
# include "utils.h"
# include "limits.h"

//horizontal.c
void	check_horizontal_lines(t_master *master);

//vertical.c
void	check_vertical_lines(t_master *master);

// set_vars.c
void	set_positions(t_master *master);
void	update_dis_t(t_master *master, t_img text);
t_img	find_texture(t_master *master);

// draw_rays.c
void	find_obs(t_master *master, float xo, float yo, char c);
void	draw_rays_3d(t_master *master);

// draw_line.c
void	draw_line(t_master *master, int point_a[2], int point_b[2], int color);

// print_minimap.c
void	print_minimap(t_master *master);

//images.c
void	upload_images(t_master *master);

#endif