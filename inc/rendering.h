/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:33 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 12:14:39 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3D.h"
# include "utils.h"
# include "limits.h"

// set_vars.c
void	set_positions(t_master *master);

// draw_rays.c
void	draw_rays_3D(t_master *master);

// draw_line.c
void	draw_line(t_master *master, int point_a[2], point_b[2], int color);

// print_minimap.c
void	print_minimap(t_master *master);

//images.c
void	upload_images(t_master *master);

#endif