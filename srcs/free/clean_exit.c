/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:51:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/22 13:02:42 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_exit(t_master *master)
{
	if (master->mlx.mlx_ptr)
		free(master->mlx.mlx_ptr);
	if (master->map.map_arr)
		free(master->map.map_arr);
	if (master)
		free(master);
	exit(1);
}