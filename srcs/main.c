/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:28:21 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/23 11:11:15 by anarebelo        ###   ########.fr       */
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
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	print_init_map(master);	
	draw_rays_3D(master);
	print_minimap(master);
	mlx_put_image_to_window(master->mlx.mlx_ptr, master->mlx.mlx_win, master->mlx.img.mlx_img, 0, 0);
	return (0);
}

/**
 * Creates an image of the size of the window and stores it in the master structure
*/
void	create_image(t_master *master)
{
	master->mlx.img.mlx_img = mlx_new_image(master->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!master->mlx.img.mlx_img)
		clean_exit(master);
	master->mlx.img.addr = mlx_get_data_addr(master->mlx.img.mlx_img, &master->mlx.img.bpp, &master->mlx.img.line_len, &master->mlx.img.endian);
	if (!master->mlx.img.addr)
		clean_exit(master);
}

/**
 * Opens a windows of a predefined size
*/
void	window_init(t_master *master)
{
	//Initial player position
	master->player.px = 1.5 * SCALE;
	master->player.py = 1.5 * SCALE;
	master->player.pa = 270;
	master->player.pdx = cos(deg_to_rad(master->player.pa));
	master->player.pdy = -sin(deg_to_rad(master->player.pa));

	master->mlx.mlx_ptr = mlx_init();
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	master->mlx.mlx_win = mlx_new_window(master->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!master->mlx.mlx_win)
	{
		free(master->mlx.mlx_ptr);
		clean_exit(master);
	}
	create_image(master);
	mlx_hook(master->mlx.mlx_win, 2, 1L<<0, &key_hook, master);
	mlx_hook(master->mlx.mlx_win, 17, 0, &red_cross, master);
	mlx_loop_hook(master->mlx.mlx_ptr, &render, master);
	mlx_loop(master->mlx.mlx_ptr);
	return ;
}


int main(int argc, char **argv)
{
	t_master	*master;

	check_args(argc, argv);
	master = ft_calloc(1, sizeof(t_master));
	if (!master)
		return (1);
	window_init(master);
	// mlx_destroy_display(master->mlx.mlx_ptr);
	free(master->mlx.mlx_ptr);
    return (0);
}