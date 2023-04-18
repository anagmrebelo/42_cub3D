/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:51:59 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/18 19:18:46 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_exit(t_master *master)
{
	if (master->mlx.mlx_ptr)
		free(master->mlx.mlx_ptr);
	if (master)
		free(master);
	exit(1);
}