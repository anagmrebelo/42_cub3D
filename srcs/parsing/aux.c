/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:24:50 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/05 13:28:40 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

void	error_control(char *msj)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(msj, 1);
}

void	save_ini_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nb_rows)
	{
		j = 0;
		while (j < map->nb_cols)
		{
			if (map->mtx[i][j] == 'N' || map->mtx[i][j] == 'S'
				|| map->mtx[i][j] == 'E' || map->mtx[i][j] == 'W')
			{
				map->view = map->mtx[i][j];
				map->px = j;
				map->py = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_isspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_control("Cannot read the map\n");
		return (-1);
	}
	return (fd);
}

int	color_parse(char *line, char a, t_map *map)
{
	if (a == 'C')
	{
		map->color_c = parse_color_array(line);
		if (!map->color_c)
			return (1);
		if (check_color(map->color_c))
			return (1);
	}
	if (a == 'F')
	{
		map->color_f = parse_color_array(line);
		if (!map->color_f)
			return (1);
		if (check_color(map->color_f))
			return (1);
	}
	return (0);
}
