/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:47:41 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/19 19:17:24 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"
#include "utils.h"
#include "free.h"

static _Bool	allow_move(t_master *master, float x, float y)
{
	int	nx;
	int	ny;
	int	final;

	nx = (int)(x) >> 6;
	ny = (int)(y) >> 6;
	final = ny * master->map.nb_rows + nx;
	printf("(%f, %f) nx: %d, ny: %d, final: %d\n", x, y, nx, ny, final);
	if ((final >= 0 && final < master->map.nb_blocks && master->map.map_arr[final] == 0))
		return (1);
	return (0);
}


/**
 * Define behaviour of WASD -> <-
*/
int	key_hook(int keycode, t_master *master)
{
	int	temp;
	
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13 && master->player.py > BLOCK
		&& allow_move(master, master->player.px + master->player.pdx * 5, master->player.py + master->player.pdy * 5)) // W == FRONT
	{
		master->player.px += master->player.pdx * 5;
		master->player.py += master->player.pdy * 5;
	}
	else if (keycode == 0 && master->player.px > BLOCK
		&& allow_move(master, master->player.px - cos(deg_to_rad(angle_check(90 - master->player.pa))) * 5, master->player.py - sin(deg_to_rad(angle_check(90 - master->player.pa))) * 5)) // A == LEFT
	{
		temp = angle_check(90 - master->player.pa);
		master->player.px -= cos(deg_to_rad(temp)) * 5;
		master->player.py -= sin(deg_to_rad(temp)) * 5;
	}
	else if (keycode == 1 && master->player.py < WINDOW_HEIGHT - BLOCK
		&& allow_move(master, master->player.px - master->player.pdx * 5, master->player.py - master->player.pdy * 5)) // S == BACK
	{
		master->player.px -= master->player.pdx * 5;
		master->player.py -= master->player.pdy * 5;
	}
	else if (keycode == 2 && master->player.px < WINDOW_WIDTH - BLOCK
		&& allow_move(master, master->player.px + cos(deg_to_rad(angle_check(90 - master->player.pa))) * 5, master->player.py + sin(deg_to_rad(angle_check(90 - master->player.pa))) * 5)) // D == RIGHT
	{
		temp = angle_check(90 - master->player.pa);
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