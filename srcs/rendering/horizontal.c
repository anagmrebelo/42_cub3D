/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:05:48 by arebelo           #+#    #+#             */
/*   Updated: 2023/06/14 19:01:48 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "rendering.h"

/**
 * Finds next horizontal line and saves distance to player in master->map.disT
*/
static void	find_obs_hor(t_master *master, float xo, float yo)
{	
	while (master->map.dof < master->map.nb_rows)
		find_obs(master, xo, yo, 'h');
}

static void	look_down(t_master *master, float tang)
{
	master->map.ry = ((int)(master->player.py / SCALE) * SCALE)
		+ master->map.block_size;
	master->map.rx = (master->player.py - master->map.ry) * tang
		+ master->player.px;
}

static void	look_up(t_master *master, float tang)
{
	master->map.ry = ((int)(master->player.py / SCALE) * SCALE) - 0.0001;
	master->map.rx = (master->player.py - master->map.ry) * tang
		+ master->player.px;
}

void	check_horizontal_lines(t_master *master)
{
	float	tang;
	float	xo;
	float	yo;

	tang = 1.0 / tan(deg_to_rad(master->map.ra));
	master->map.dof = 0;
	if (master->map.ra < 180 && master->map.ra > 0 && !isnan(tang))
	{
		look_up(master, tang);
		yo = -master->map.block_size;
		xo = -yo * tang;
	}
	else if (master->map.ra > 180 && !isnan(tang))
	{
		look_down(master, tang);
		yo = master->map.block_size;
		xo = -yo * tang;
	}
	else
	{
		master->map.rx = master->player.px;
		master->map.ry = master->player.py;
		return ;
	}
	find_obs_hor(master, xo, yo);
}
