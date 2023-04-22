/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:07:57 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/22 13:09:11 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "free.h"

int	red_cross(t_master *master)
{
	mlx_destroy_window(master->mlx.mlx_ptr, master->mlx.mlx_win);
	clean_exit(master);
	return (0);
}