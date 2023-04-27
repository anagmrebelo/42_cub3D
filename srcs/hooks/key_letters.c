/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:32:04 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/27 17:36:42 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "hooks.h"
#include "utils.h"

void	move_front(t_master *master)
{
	if (allow_move(master,
			master->player.px + master->player.pdx * PLAYER_SPEED,
			master->player.py + master->player.pdy * PLAYER_SPEED))
	{
		master->player.px += master->player.pdx * PLAYER_SPEED;
		master->player.py += master->player.pdy * PLAYER_SPEED;
	}
	else if (allow_move(master,
			master->player.px + master->player.pdx * PLAYER_SPEED,
			master->player.py))
		master->player.px += master->player.pdx * PLAYER_SPEED;
	else if (allow_move(master, master->player.px,
			master->player.py + master->player.pdy * PLAYER_SPEED))
		master->player.py += master->player.pdy * PLAYER_SPEED;
}

void	move_left(t_master *master)
{
	int	temp;

	temp = angle_check(90 - master->player.pa);
	if (allow_move(master,
			master->player.px - cos(deg_to_rad(temp)) * PLAYER_SPEED,
			master->player.py - sin(deg_to_rad(temp)) * PLAYER_SPEED))
	{
		master->player.px -= cos(deg_to_rad(temp)) * PLAYER_SPEED;
		master->player.py -= sin(deg_to_rad(temp)) * PLAYER_SPEED;
	}
	else if (allow_move(master,
			master->player.px - cos(deg_to_rad(temp)) * PLAYER_SPEED,
			master->player.py))
		master->player.px -= cos(deg_to_rad(temp)) * PLAYER_SPEED;
	else if (allow_move(master, master->player.px,
			master->player.py - sin(deg_to_rad(temp)) * PLAYER_SPEED))
		master->player.py -= sin(deg_to_rad(temp)) * PLAYER_SPEED;
}

void	move_back(t_master *master)
{
	if (allow_move(master,
			master->player.px - master->player.pdx * PLAYER_SPEED,
			master->player.py - master->player.pdy * PLAYER_SPEED))
	{
		master->player.px -= master->player.pdx * PLAYER_SPEED;
		master->player.py -= master->player.pdy * PLAYER_SPEED;
	}
	else if (allow_move(master,
			master->player.px - master->player.pdx * PLAYER_SPEED,
			master->player.py))
		master->player.px -= master->player.pdx * PLAYER_SPEED;
	else if (allow_move(master, master->player.px,
			master->player.py - master->player.pdy * PLAYER_SPEED))
		master->player.py -= master->player.pdy * PLAYER_SPEED;
}

void	move_right(t_master *master)
{
	int	temp;

	temp = angle_check(90 - master->player.pa);
	if (allow_move(master,
			master->player.px + cos(deg_to_rad(temp)) * PLAYER_SPEED,
			master->player.py + sin(deg_to_rad(temp)) * PLAYER_SPEED))
	{
		master->player.px += cos(deg_to_rad(temp)) * PLAYER_SPEED;
		master->player.py += sin(deg_to_rad(temp)) * PLAYER_SPEED;
	}
	else if (allow_move(master,
			master->player.px + cos(deg_to_rad(temp)) * PLAYER_SPEED,
			master->player.py))
		master->player.px += cos(deg_to_rad(temp)) * PLAYER_SPEED;
	else if (allow_move(master, master->player.px,
			master->player.py + sin(deg_to_rad(temp)) * PLAYER_SPEED))
		master->player.py += sin(deg_to_rad(temp)) * PLAYER_SPEED;
}
