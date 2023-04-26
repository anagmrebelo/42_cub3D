/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:33 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/24 18:20:09 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3D.h"
# include "utils.h"
# include "limits.h"

void	print_init_map(t_master *master);
void	draw_rays_3D(t_master *master);
void 	draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color);

// print_minimap.c
void	print_minimap(t_master *master);

//images.c
void	upload_images(t_master *master);

#endif