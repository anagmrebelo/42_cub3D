/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:28:21 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/16 20:09:53 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"
#include "free.h"
#include "utils.h"
#include "hooks.h"
#include "rendering.h"

int	render(t_master *master)
{
	if (!master->mlx.mlx_ptr)
		clean_exit(master);
	print_init_map(master);	
	draw_rays_3D(master);
	print_player(master, YELLOW_PIXEL);
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
	master->player.px = 300;
	master->player.py = 300;
	master->player.pa = 5 * PI/4;
	master->player.pdx = cos(master->player.pa) * 10;
	master->player.pdy = sin(master->player.pa) * 10;

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
	mlx_key_hook(master->mlx.mlx_win, &key_hook, master);
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