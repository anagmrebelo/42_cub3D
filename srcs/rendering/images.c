/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:10:36 by arebelo           #+#    #+#             */
/*   Updated: 2023/06/14 19:02:00 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "free.h"
#include "parsing.h"

/**
 * Creates an image of the size of the window 
 * stores it in the master structure
*/
static void	create_game_image(t_master *master)
{
	master->mlx.img.mlx_img = mlx_new_image(master->mlx.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!master->mlx.img.mlx_img)
		clean_exit(master);
	master->mlx.img.addr = mlx_get_data_addr(master->mlx.img.mlx_img,
			&master->mlx.img.bpp, &master->mlx.img.line_len,
			&master->mlx.img.endian);
	if (!master->mlx.img.addr)
		clean_exit(master);
}

/**
 * Exits the program if image width and height is different from 64 pixels
*/
static void	check_64(t_master *master, t_img *img)
{
	if (img->width == 64 && img->height == 64)
		return ;
	printf("Insert only textures of 64 x 64 pixlels\n");
	clean_exit(master);
}

/***
 *	Saves as the file given by path in the structure img 
*/
static void	save_image(t_master *master, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(master->mlx.mlx_ptr,
			path, &img->width, &img->height);
	if (!img->mlx_img)
	{
		error_control("Couldn't convert file xpm to image.\n", 1);
		clean_exit(master);
	}
	img->addr = mlx_get_data_addr(
			img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
		clean_exit(master);
	check_64(master, img);
}

/**
 * Saves the 4 wall textures in master structure
*/
static void	upload_textures(t_master *master)
{
	save_image(master, &master->map.north, master->map.tex_no);
	save_image(master, &master->map.south, master->map.tex_so);
	save_image(master, &master->map.east, master->map.tex_ea);
	save_image(master, &master->map.west, master->map.tex_we);
}

/**
 * Upload texture xpm and create a new image for the game
*/
void	upload_images(t_master *master)
{
	create_game_image(master);
	upload_textures(master);
}
