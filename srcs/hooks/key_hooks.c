/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:47:41 by anarebelo         #+#    #+#             */
/*   Updated: 2023/06/14 19:00:15 by mrollo           ###   ########.fr       */
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
	if (master->mlx.keys.w == 1)
		move_front(master);
	if (master->mlx.keys.a)
		move_left(master);
	if (master->mlx.keys.s)
		move_back(master);
	if (master->mlx.keys.d)
		move_right(master);
	if (master->mlx.keys.l)
		move_larrow(master);
	if (master->mlx.keys.r)
		move_rarrow(master);
}

/**
 * When key is pressed, update master->mlx->keys for TRUE
*/
int	key_down(int keycode, t_master *master)
{
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13)
		master->mlx.keys.w = 1;
	else if (keycode == 0)
		master->mlx.keys.a = 1;
	else if (keycode == 1)
		master->mlx.keys.s = 1;
	else if (keycode == 2)
		master->mlx.keys.d = 1;
	else if (keycode == 123)
		master->mlx.keys.l = 1;
	else if (keycode == 124)
		master->mlx.keys.r = 1;
	else if (keycode == 53)
		esc(master);
	return (0);
}

/**
 * When key is released, update master->mlx->keys for FALSE
*/
int	key_up(int keycode, t_master *master)
{
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	if (keycode == 13)
		master->mlx.keys.w = 0;
	else if (keycode == 0)
		master->mlx.keys.a = 0;
	else if (keycode == 1)
		master->mlx.keys.s = 0;
	else if (keycode == 2)
		master->mlx.keys.d = 0;
	else if (keycode == 123)
		master->mlx.keys.l = 0;
	else if (keycode == 124)
		master->mlx.keys.r = 0;
	else if (keycode == 53)
		esc(master);
	return (0);
}
