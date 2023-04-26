/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:51:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 16:23:42 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Frees t_master structure
*/
void	clean_exit(t_master *master)
{
	// Destroy images
	if (master->mlx.img.mlx_img)
		mlx_destroy_image(master->mlx.mlx_ptr, master->mlx.img.mlx_img);
	if (master->map.north.mlx_img)
		mlx_destroy_image(master->mlx.mlx_ptr, master->map.north.mlx_img);
	if (master->map.south.mlx_img)
		mlx_destroy_image(master->mlx.mlx_ptr, master->map.south.mlx_img);
	if (master->map.east.mlx_img)
		mlx_destroy_image(master->mlx.mlx_ptr, master->map.east.mlx_img);
	if (master->map.west.mlx_img)
		mlx_destroy_image(master->mlx.mlx_ptr, master->map.west.mlx_img);
	
	// Destroy window
	if (master->mlx.mlx_win)
		mlx_destroy_window(master->mlx.mlx_ptr, master->mlx.mlx_win);

	// Mica clean
	if (master)
		free(master);
	exit(1);
}