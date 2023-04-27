/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:47:41 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/27 14:48:58 by arebelo          ###   ########.fr       */
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

	nx = (int)(x) / SCALE;
	ny = (int)(y) / SCALE;
	if (nx < 0 || ny < 0)
		return (0);
	if ((nx < master->map.nb_cols && ny < master->map.nb_rows && master->map.mtx[ny][nx] != '1'))
		return (1);
	return (0);
}

static void	move_front(t_master *master)
{
	if (allow_move(master, master->player.px + master->player.pdx * PLAYER_SPEED, master->player.py + master->player.pdy * PLAYER_SPEED))
		{
			master->player.px += master->player.pdx * PLAYER_SPEED;
			master->player.py += master->player.pdy * PLAYER_SPEED;
		}
		else if (allow_move(master, master->player.px + master->player.pdx * PLAYER_SPEED, master->player.py))
			master->player.px += master->player.pdx * PLAYER_SPEED;
		else if (allow_move(master, master->player.px, master->player.py + master->player.pdy * PLAYER_SPEED))
			master->player.py += master->player.pdy * PLAYER_SPEED;
}

static void	move_left(t_master *master)
{
	int	temp;

	temp = angle_check(90 - master->player.pa);
		if (allow_move(master, master->player.px - cos(deg_to_rad(temp)) * PLAYER_SPEED, master->player.py - sin(deg_to_rad(temp)) * PLAYER_SPEED))
		{
			master->player.px -= cos(deg_to_rad(temp)) * PLAYER_SPEED;
			master->player.py -= sin(deg_to_rad(temp)) * PLAYER_SPEED;
		}
		else if (allow_move(master, master->player.px - cos(deg_to_rad(temp)) * PLAYER_SPEED, master->player.py))
			master->player.px -= cos(deg_to_rad(temp)) * PLAYER_SPEED;
		else if (allow_move(master, master->player.px, master->player.py - sin(deg_to_rad(temp)) * PLAYER_SPEED))
			master->player.py -= sin(deg_to_rad(temp)) * PLAYER_SPEED;
}

static void	move_back(t_master *master)
{
	if (allow_move(master, master->player.px - master->player.pdx * PLAYER_SPEED, master->player.py - master->player.pdy * PLAYER_SPEED))
		{
			master->player.px -= master->player.pdx * PLAYER_SPEED;
			master->player.py -= master->player.pdy * PLAYER_SPEED;
		}
		else if (allow_move(master, master->player.px - master->player.pdx * PLAYER_SPEED, master->player.py))
			master->player.px -= master->player.pdx * PLAYER_SPEED;
		else if (allow_move(master, master->player.px, master->player.py - master->player.pdy * PLAYER_SPEED))
			master->player.py -= master->player.pdy * PLAYER_SPEED;
}

static void	move_right(t_master *master)
{
	int	temp;

	temp = angle_check(90 - master->player.pa);
	if (allow_move(master, master->player.px + cos(deg_to_rad(temp)) * PLAYER_SPEED, master->player.py + sin(deg_to_rad(temp)) * PLAYER_SPEED))
	{
		master->player.px += cos(deg_to_rad(temp)) * PLAYER_SPEED;
		master->player.py += sin(deg_to_rad(temp)) * PLAYER_SPEED;
	}
	else if (allow_move(master, master->player.px + cos(deg_to_rad(temp)) * PLAYER_SPEED, master->player.py))
		master->player.px += cos(deg_to_rad(temp)) * PLAYER_SPEED;
	else if (allow_move(master, master->player.px, master->player.py + sin(deg_to_rad(temp)) * PLAYER_SPEED))
		master->player.py += sin(deg_to_rad(temp)) * PLAYER_SPEED;
}

static void	move_larrow(t_master *master)
{
	master->player.pa = angle_check(master->player.pa + ANGLE_SPEED);
	master->player.pdx = cos(deg_to_rad(master->player.pa));
	master->player.pdy = -sin(deg_to_rad(master->player.pa));
}

static void	move_rarrow(t_master *master)
{
	master->player.pa = angle_check(master->player.pa - ANGLE_SPEED);
	master->player.pdx = cos(deg_to_rad(master->player.pa));
	master->player.pdy = -sin(deg_to_rad(master->player.pa));
}

static void	esc(t_master *master)
{
	clean_exit(master);
}

/**
 * Define behaviour of WASD -> <-
*/
int	key_hook(int keycode, t_master *master)
{	
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13) // W == FRONT
		move_front(master);
	else if (keycode == 0) // A == LEFT
		move_left(master);
	else if (keycode == 1) // S == BACK
		move_back(master);
	else if (keycode == 2) // D == RIGHT
		move_right(master);
	else if (keycode == 123) // Left arrow <-
		move_larrow(master);
	else if (keycode == 124) // Right arrow ->
		move_rarrow(master);
	else if (keycode == 53)
		esc(master);	// ESC
	return (0);
}
