/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:32:04 by arebelo           #+#    #+#             */
/*   Updated: 2023/06/11 17:42:12 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "hooks.h"
#include "utils.h"

void	move_front(t_master *master)
{
	int	counter;

	counter = 0;
	while (counter < PLAYER_SPEED)
	{
		if (allow_move(master,
				master->player.px + master->player.pdx,
				master->player.py))
			master->player.px += master->player.pdx;
		if (allow_move(master,
				master->player.px,
				master->player.py + master->player.pdy))
			master->player.py += master->player.pdy;
		counter++;
	}
}

void	move_left(t_master *master)
{
	int	counter;
	int	temp;

	counter = 0;
	temp = angle_check(90 - master->player.pa);
	while (counter < PLAYER_SPEED)
	{
		if (allow_move(master,
				master->player.px - cos(deg_to_rad(temp)) ,
				master->player.py))
			master->player.px -= cos(deg_to_rad(temp));
		if (allow_move(master,
				master->player.px,
				master->player.py - sin(deg_to_rad(temp))))
			master->player.py -= sin(deg_to_rad(temp));
		counter++;
	}
}

void	move_back(t_master *master)
{
	int	counter;

	counter = 0;
	while (counter < PLAYER_SPEED)
	{
		if (allow_move(master,
				master->player.px - master->player.pdx,
				master->player.py))
			master->player.px -= master->player.pdx;
		if (allow_move(master,
				master->player.px,
				master->player.py - master->player.pdy))
			master->player.py -= master->player.pdy;
		counter++;
	}
}

void	move_right(t_master *master)
{	
	int	counter;
	int	temp;

	counter = 0;
	temp = angle_check(90 - master->player.pa);
	while (counter < PLAYER_SPEED)
	{
		if (allow_move(master,
				master->player.px + cos(deg_to_rad(temp)) ,
				master->player.py))
			master->player.px += cos(deg_to_rad(temp));
		if (allow_move(master,
				master->player.px,
				master->player.py + sin(deg_to_rad(temp))))
			master->player.py += sin(deg_to_rad(temp));
		counter++;
	}
}
