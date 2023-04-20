/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:33 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/20 18:27:10 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3D.h"
# include "utils.h"
# include "limits.h"

void	print_player(t_master *master, int color);
void	print_init_map(t_master *master);
void	draw_rays_3D(t_master *master);
void 	draw_line(t_master *master, int beginX, int beginY, int endX, int endY, int color);

#endif