/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:47:41 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/19 14:49:29 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"
#include "utils.h"
#include "free.h"

/**
 * Define behaviour of WASD -> <-
*/
int	key_hook(int keycode, t_master *master)
{
	int	temp;
	
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13 && master->player.py > BLOCK) // W == FRONT
	{
		master->player.px += master->player.pdx * 5;
		master->player.py += master->player.pdy * 5;
	}
	else if (keycode == 0 && master->player.px > BLOCK) // A == LEFT
	{
		temp = 90 - master->player.pa;
		temp = angle_check(temp);
		master->player.px -= cos(deg_to_rad(temp)) * 5;
		master->player.py -= sin(deg_to_rad(temp)) * 5;
	}
	else if (keycode == 1 && master->player.py < WINDOW_HEIGHT - BLOCK) // S == BACK
	{
		master->player.px -= master->player.pdx * 5;
		master->player.py -= master->player.pdy * 5;
	}
	else if (keycode == 2 && master->player.px < WINDOW_WIDTH - BLOCK) // D == RIGHT
	{
		temp = 90 - master->player.pa;
		temp = angle_check(temp);
		master->player.px += cos(deg_to_rad(temp)) * 5;
		master->player.py += sin(deg_to_rad(temp)) * 5;
	}
	else if (keycode == 123) // Left arrow <-
	{
		master->player.pa = angle_check(master->player.pa + 5);
		master->player.pdx = cos(deg_to_rad(master->player.pa));
		master->player.pdy = -sin(deg_to_rad(master->player.pa));

	}
	else if (keycode == 124) // Right arrow ->
	{
		master->player.pa = angle_check(master->player.pa - 5);
		master->player.pdx = cos(deg_to_rad(master->player.pa));
		master->player.pdy = -sin(deg_to_rad(master->player.pa));
	}
	return (0);
}