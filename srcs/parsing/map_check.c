/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:24:56 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/03 15:34:06 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

int	check_nb_rows(char *row, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (row[i] == ' ' || row[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_nb_cols(char **map, int rows, int j)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][j] == ' ' || map[i][j] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_round_2(char **map, int x, int y)
{
	if ((map[x][y - 1] == ' ') || (map[x][y + 1] == ' ') || (map[x + 1][y] == ' ') || (map[x - 1][y] == ' '))
		return (1);
	return (0);
}

int	check_round(char **map, int x, int y)
{
	if ((map[x][y - 1] == ' ' || map[x][y - 1] == '1')
		&& (map[x][y + 1] == ' ' || map[x][y + 1] == '1')
		&& (map[x + 1][y] == ' ' || map[x + 1][y] == '1')
		&& (map[x - 1][y] == ' ' || map[x - 1][y] == '1'))
		return (0);
	return (1);
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
		printf("The map is not closed or has a wrong char in the 'walls'\n");
		return (1);
	}
	i = 0;
	while (++i < map->nb_rows - 1)
	{
		j = 0;
		while (++j < map->nb_cols - 1)
		{
			if (mtx[i][j] == ' ')
			{
				if (check_round(mtx, i, j))
				{
					error_control("The map has to be closed\n");
					return (1);
				}
			}
			if (mtx[i][j] == '0')
			{
				if (check_round_2(mtx, i, j))
				{
					error_control("The map has to be closed\n");
					return (1);
				}
			}
		}
	}
	return (0);
}
