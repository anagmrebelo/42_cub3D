/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:51:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 13:03:06 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
# include "parsing.h"

/**
 * Frees t_master structure
*/
void	clean_exit(t_master *master)
{
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
	if (master->mlx.mlx_win)
		mlx_destroy_window(master->mlx.mlx_ptr, master->mlx.mlx_win);

	// Mica clean
	if (master->map.mtx)
		free_tab(master->map.mtx);
	if (master->map.str_map)
		free(master->map.str_map);
	if (master->map.tex_ea)
		free(master->map.tex_ea);
	if (master->map.tex_we)
		free(master->map.tex_we);
	if (master->map.tex_so)
		free(master->map.tex_so);
	if (master->map.tex_no)
		free(master->map.tex_no);
	if (master->map.color_c)
		free (master->map.color_c);
	if (master->map.color_f)
		free (master->map.color_f);

	if (master)
		free(master);
	exit(1);
}
