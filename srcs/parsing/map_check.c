/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:24:56 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/26 15:24:57 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
# include "parsing.h"

int	check_map_row(char *row, int cols)
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

int	check_map_col(char **map, int rows, int j)
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

int	check_round(char **map, int x, int y)
{
	if ((map[x][y - 1] == ' ' || map[x][y - 1] == '1')
		&& (map[x][y + 1] == ' ' || map[x][y + 1] == '1')
		&& (map[x + 1][y] == ' ' || map[x + 1][y] == '1')
		&& (map[x - 1][y] == ' ' || map[x - 1][y] == '1'))
			return (0);
	return (1);
}

int	check_map(char **map, t_data *data)
{
	int	i;
	int	j;

	if (check_map_row(map[0], data->map_col)
		|| check_map_row(map[data->map_row - 1], data->map_col)
		|| check_map_col(map, data->map_row, 0)
		|| check_map_col(map, data->map_row, (data->map_col - 1)))
	{
		printf("The map is not closed\n");
		return (1);
	}
	i = 0;
	while (++i < data->map_row - 1)
	{
		j = 0;
		while (++j < data->map_col - 1)
		{
			if (map[i][j] == ' ')
			{
				if (check_round(map, i, j))
				{
					printf("not closed desde check\n");
					return (1);
				}
			}
		}
	}
	return (0);
}