/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:28:21 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 12:29:24 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"
#include "free.h"
#include "utils.h"
#include "hooks.h"
#include "rendering.h"

/**
 * Prints background and rays into image
 * Pushes image to screen
*/
int	render(t_master *master)
{
	key_hook(master);
	draw_rays_3d(master);
	print_minimap(master);
	mlx_put_image_to_window(master->mlx.mlx_ptr,
		master->mlx.mlx_win, master->mlx.img.mlx_img, 0, 0);
	return (0);
}

/**
 * Opens a windows of a predefined size and uploads textures
*/
static void	window_init(t_master *master)
{
	// Create mlx and window
	master->mlx.mlx_ptr = mlx_init();
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	master->mlx.mlx_win = mlx_new_window(master->mlx.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!master->mlx.mlx_win)
		clean_exit(master);
	// Upload texture images and create new img for game
	upload_images(master);
	//Define player initial pos
	set_positions(master);
	return ;
}

/**
 * Set key and image hooks
*/
static void	window_loops(t_master *master)
{
	// Key hooks
	mlx_hook(master->mlx.mlx_win, 2, 1L << 0, &key_down, master);
	mlx_hook(master->mlx.mlx_win, 3, 1L << 0, &key_up, master);
	// Red cross hook
	mlx_hook(master->mlx.mlx_win, 17, 0, &red_cross, master);
	// Changes on image
	mlx_loop_hook(master->mlx.mlx_ptr, &render, master);
	// Maintain window open 
	mlx_loop(master->mlx.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_master	*master;

	master = ft_calloc(1, sizeof(t_master));
	if (!master)
		return (1);
	check_args(argc, argv, master);
	window_init(master);
	window_loops(master);
	clean_exit(master);
}
