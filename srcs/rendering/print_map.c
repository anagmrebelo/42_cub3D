/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:28:18 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/24 13:05:00 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "free.h"

void	print_init_map(t_master *master)
{
	int map[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
	
	master->map.nb_cols = 11;
	master->map.nb_rows = 8;
	master->map.nb_blocks = master->map.nb_cols * master->map.nb_rows;
	master->map.map_arr = ft_calloc(master->map.nb_blocks, sizeof(int));
	master->map.block_size = SCALE;
	master->map.ceil_col = BLUE_PIXEL;
	master->map.floor_col = GREEN_PIXEL;
	ft_memcpy(master->map.map_arr, map, master->map.nb_blocks * sizeof(int));
	if (master->map.nb_cols > master->map.nb_rows)
		master->map.map_s = MINIMAP_SIZE / master->map.nb_cols;
	else
		master->map.map_s = MINIMAP_SIZE / master->map.nb_rows;

	// North
	master->map.north.mlx_img = mlx_xpm_file_to_image(master->mlx.mlx_ptr, "srcs/imgs/wall_text/a.xpm", &master->map.north.width, &master->map.north.height);
	if (!master->map.north.mlx_img)
		clean_exit(master);
	master->map.north.addr = mlx_get_data_addr(
			master->map.north.mlx_img, &master->map.north.bpp, &master->map.north.line_len, &master->map.north.endian);
	if (!master->map.north.addr)
		clean_exit(master);
	// South
	master->map.south.mlx_img = mlx_xpm_file_to_image(master->mlx.mlx_ptr, "srcs/imgs/wall_text/e.xpm", &master->map.south.width, &master->map.south.height);
	if (!master->map.south.mlx_img)
		clean_exit(master);
	master->map.south.addr = mlx_get_data_addr(
			master->map.south.mlx_img, &master->map.south.bpp, &master->map.south.line_len, &master->map.south.endian);
	if (!master->map.south.addr)
		clean_exit(master);
	// East
	master->map.east.mlx_img = mlx_xpm_file_to_image(master->mlx.mlx_ptr, "srcs/imgs/wall_text/c.xpm", &master->map.east.width, &master->map.east.height);
	if (!master->map.east.mlx_img)
		clean_exit(master);
	master->map.east.addr = mlx_get_data_addr(
			master->map.east.mlx_img, &master->map.east.bpp, &master->map.east.line_len, &master->map.east.endian);
	if (!master->map.east.addr)
		clean_exit(master);
	// West
	master->map.west.mlx_img = mlx_xpm_file_to_image(master->mlx.mlx_ptr, "srcs/imgs/wall_text/d.xpm", &master->map.west.width, &master->map.west.height);
	if (!master->map.west.mlx_img)
		clean_exit(master);
	master->map.west.addr = mlx_get_data_addr(
			master->map.west.mlx_img, &master->map.west.bpp, &master->map.west.line_len, &master->map.west.endian);
	if (!master->map.west.addr)
		clean_exit(master);
}