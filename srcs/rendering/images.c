/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:10:36 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/26 15:14:25 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "free.h"

/**
 * Creates an image of the size of the window and stores it in the master structure
*/
static void	create_game_image(t_master *master)
{
	master->mlx.img.mlx_img = mlx_new_image(master->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!master->mlx.img.mlx_img)
		clean_exit(master);
	master->mlx.img.addr = mlx_get_data_addr(master->mlx.img.mlx_img, &master->mlx.img.bpp, &master->mlx.img.line_len, &master->mlx.img.endian);
	if (!master->mlx.img.addr)
		clean_exit(master);
}

/***
 *	Saves as the file given by path in the structure img 
*/
static void	save_image(t_master *master, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(master->mlx.mlx_ptr, path, &img->width, &img->height);
	if (!img->mlx_img)
		clean_exit(master);
	img->addr = mlx_get_data_addr(
			img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
		clean_exit(master);
}

/**
 * Saves the 4 wall textures in master structure
*/
static void	upload_textures(t_master *master)
{
	save_image(master, &master->map.north, "srcs/imgs/wall_text/a.xpm");	// North
	save_image(master, &master->map.south, "srcs/imgs/wall_text/b.xpm");	// South
	save_image(master, &master->map.east, "srcs/imgs/wall_text/c.xpm");		// East
	save_image(master, &master->map.west, "srcs/imgs/wall_text/d.xpm");		// West	
}

/**
 * Upload texture xpm and create a new image for the game
*/
void	upload_images(t_master *master)
{
	create_game_image(master);
	upload_textures(master);	
}
