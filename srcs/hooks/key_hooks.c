/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:47:41 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/27 18:52:07 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"
#include "utils.h"
#include "free.h"
#include "hooks.h"

/**
 * Checks if position (x, y) is wall
*/
_Bool	allow_move(t_master *master, float x, float y)
{
	int	nx;
	int	ny;

	nx = (int)(x) / SCALE;
	ny = (int)(y) / SCALE;
	if (nx < 0 || ny < 0)
		return (0);
	if ((nx < master->map.nb_cols && ny < master->map.nb_rows
			&& master->map.mtx[ny][nx] != '1'))
		return (1);
	return (0);
}

static void	esc(t_master *master)
{
	clean_exit(master);
}

/**
 * Define behaviour of WASD -> <-
*/
void	key_hook(t_master *master)
{	
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (master->mlx.keys.w == 1) // W == FRONT
		move_front(master);
	if (master->mlx.keys.a) // A == LEFT
		move_left(master);
	if (master->mlx.keys.s) // S == BACK
		move_back(master);
	if (master->mlx.keys.d) // D == RIGHT
		move_right(master);
	if (master->mlx.keys.l) // Left arrow <-
		move_larrow(master);
	if (master->mlx.keys.r) // Right arrow ->
		move_rarrow(master);
}

/**
 * When key is pressed, update master->mlx->keys for TRUE
*/
int	key_down(int keycode, t_master *master)
{
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13) // W == FRONT
		master->mlx.keys.w = 1;
	else if (keycode == 0) // A == LEFT
		master->mlx.keys.a = 1;
	else if (keycode == 1) // S == BACK
		master->mlx.keys.s = 1;
	else if (keycode == 2) // D == RIGHT
		master->mlx.keys.d = 1;
	else if (keycode == 123) // Left arrow <-
		master->mlx.keys.l = 1;
	else if (keycode == 124) // Right arrow ->
		master->mlx.keys.r = 1;
	else if (keycode == 53)
		esc(master); // ESC
	return (0);
}

/**
 * When key is released, update master->mlx->keys for FALSE
*/
int	key_up(int keycode, t_master *master)
{
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13) // W == FRONT
		master->mlx.keys.w = 0;
	else if (keycode == 0) // A == LEFT
		master->mlx.keys.a = 0;
	else if (keycode == 1) // S == BACK
		master->mlx.keys.s = 0;
	else if (keycode == 2) // D == RIGHT
		master->mlx.keys.d = 0;
	else if (keycode == 123) // Left arrow <-
		master->mlx.keys.l = 0;
	else if (keycode == 124) // Right arrow ->
		master->mlx.keys.r = 0;
	else if (keycode == 53)
		esc(master); // ESC
	return (0);
}
