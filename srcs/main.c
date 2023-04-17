/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:28:21 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/17 16:42:37 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

/**
 * Opens a windows of a predefined size
*/
void	window_init(t_master *master)
{
	void	*mlx;
	void	*mlx_win;

	//Initial player position
	master->player.px = 300;
	master->player.py = 300;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 512, "cub3D");
	mlx_loop(mlx);
	return ;
}


int main(int argc, char **argv)
{
	// t_master	*master;

	check_args(argc, argv);
	read_file(argv[1]);
	// master = ft_calloc(1, sizeof(t_master));
	// if (!master)
	// 	return (1);
	// window_init(master);
    return (0);
}