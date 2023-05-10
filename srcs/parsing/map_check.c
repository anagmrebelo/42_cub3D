/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:24:56 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 14:34:32 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

static int	check_round(char **map, int x, int y)
{
	if ((map[x][y - 1] == ' ' || map[x][y - 1] == '1')
		&& (map[x][y + 1] == ' ' || map[x][y + 1] == '1')
		&& (map[x + 1][y] == ' ' || map[x + 1][y] == '1')
		&& (map[x - 1][y] == ' ' || map[x - 1][y] == '1'))
		return (0);
	return (1);
}

static int	aux_check_map(char c, char **map, int i, int j)
{
	if (c == ' ')
	{
		if (check_round(map, i, j))
		{
			error_control("The map has to be closed\n");
			return (1);
		}
	}
	if (c == '0')
	{
		if (check_round_2(map, i, j))
		{
			error_control("The map has to be closed\n");
			return (1);
		}
	}
	return (0);
}

int	check_round_2(char **map, int x, int y)
{
	if ((map[x][y - 1] == ' ') || (map[x][y + 1] == ' ')
		|| (map[x + 1][y] == ' ') || (map[x - 1][y] == ' '))
		return (1);
	return (0);
}

int	check_map(char **mtx, t_map *map)
{
	int	i;
	int	j;

	if (check_nb_rows(mtx[0], map->nb_cols)
		|| check_nb_rows(mtx[map->nb_rows - 1], map->nb_cols)
		|| check_nb_cols(mtx, map->nb_rows, 0)
		|| check_nb_cols(mtx, map->nb_rows, (map->nb_cols - 1)))
	{
		error_control("The map not closed or wrong char in the 'walls'\n");
		return (1);
	}
	i = 0;
	while (++i < map->nb_rows - 1)
	{
		j = 0;
		while (++j < map->nb_cols - 1)
		{
			if (aux_check_map(mtx[i][j], mtx, i, j))
				return (1);
		}
	}
	return (0);
}
