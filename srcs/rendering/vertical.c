/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:08:32 by arebelo           #+#    #+#             */
/*   Updated: 2023/06/14 19:02:27 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "rendering.h"

/**
 * Finds next vertical line and saves distance to player in master->map.disT
*/
static void	find_obs_vert(t_master *master, float xo, float yo)
{	
	while (master->map.dof < master->map.nb_cols)
		find_obs(master, xo, yo, 'v');
}

static void	look_right(t_master *master, float tang)
{
	master->map.rx = ((int)(master->player.px / SCALE) * SCALE)
		+ master->map.block_size;
	master->map.ry = (master->player.px - master->map.rx) * tang
		+ master->player.py;
}

static void	look_left(t_master *master, float tang)
{
	master->map.rx = ((int)(master->player.px / SCALE) * SCALE) - 0.0001;
	master->map.ry = (master->player.px - master->map.rx) * tang
		+ master->player.py;
}

void	check_vertical_lines(t_master *master)
{
	float	tang;
	float	xo;
	float	yo;

	master->map.dof = 0;
	tang = tan(deg_to_rad(master->map.ra));
	if (master->map.ra < 90 || master->map.ra > 270)
	{
		look_right(master, tang);
		xo = master->map.block_size;
		yo = -xo * tang;
	}
	else if (master->map.ra > 90 && master->map.ra < 270)
	{
		look_left(master, tang);
		xo = -master->map.block_size;
		yo = -xo * tang;
	}
	else
	{
		master->map.rx = master->player.px;
		master->map.ry = master->player.py;
		return ;
	}
	find_obs_vert(master, xo, yo);
}
