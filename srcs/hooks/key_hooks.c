/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:47:41 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 19:45:27 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"

#define BLACK_PIXEL 0x000000

int	key_hook(int keycode, t_master *master)
{
	if (!master->mlx.mlx_ptr)
		exit(1); //@arebelo protect
	if (keycode == 13 && master->player.py > BLOCK) // W
	{
		master->player.px += master->player.pdx;
		master->player.py += master->player.pdy;
	}
	else if (keycode == 0 && master->player.px > BLOCK) // A
	{
		master->player.px -= cos(PI/2 + master->player.pa) * 5;
		master->player.py -= sin(PI/2 + master->player.pa) * 5;
	}
	else if (keycode == 1 && master->player.py < WINDOW_HEIGHT - BLOCK) // S
	{
		master->player.px -= master->player.pdx;
		master->player.py -= master->player.pdy;
	}
	else if (keycode == 2 && master->player.px < WINDOW_WIDTH - BLOCK) // D
	{
		master->player.px += cos(PI/2 + master->player.pa) * 5;
		master->player.py += sin(PI/2 + master->player.pa) * 5;
	}
	else if (keycode == 123)
	{
		master->player.pa -= 0.1;
		if (master->player.pa < 0)
			master->player.pa += 2 * PI;
		master->player.pdx = cos(master->player.pa) * 5;
		master->player.pdy = sin(master->player.pa) * 5;

	}
	else if (keycode == 124)
	{
		master->player.pa += 0.1;
		if (master->player.pa > 2 * PI)
			master->player.pa -= 2 * PI;
		master->player.pdx = cos(master->player.pa) * 5;
		master->player.pdy = sin(master->player.pa) * 5;
	}
	return (0);
}