/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:55:52 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 20:40:17 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "parsing.h"
#include "utils.h"

static int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_control("Cannot read the map\n", -1);
		return (-1);
	}
	return (fd);
}

static int	aux_check_line(char a, char b, char *line, t_map *map)
{
	if ((a == 'N' && b == 'O') || (a == 'S' && b == 'O')
		|| (a == 'E' && b == 'A') || (a == 'W' && b == 'E'))
	{
		if (tex_parse_aux(a, b, line, map))
			return (2);
		return (1);
	}
	if (a == 'C' || a == 'F')
	{
		if (color_parse(line, a, map))
			return (error_control("Color not valid or missing color\n", 2));
		return (1);
	}
	else
		return (error_control("Shit on the .cub\n", 2));
}

static int	check_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (!ft_isspace(line))
	{
		if (map->mp == 1)
			return (error_control("Invalid map\n", 2));
		return (1);
	}
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] > 64 && line[i] < 91)
			return (aux_check_line(line[i], line[i + 1], line, map));
		if (line[i] == '1')
			return (0);
		else
			return (error_control("Shit on the .cub\n", 2));
	}
	return (0);
}

static int	checking(char *line, t_map *map)
{
	int	chk;
	int	len;

	chk = check_line(line, map);
	if (chk == 1)
	{
		free (line);
		return (0);
	}
	else if (chk == 2)
	{
		free (line);
		return (1);
	}
	else
	{
		map->mp = 1;
		len = ft_strlen(line) - 1;
		if (len > map->nb_cols)
			map->nb_cols = len;
		map->str_map = join_free_s1(map->str_map, line);
		map->nb_rows++;
		free (line);
	}
	return (0);
}

int	read_file(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int		exit;

	fd = check_path(path);
	if (fd < 0)
		return (1);
	line = NULL;
	exit = 0;
	map->mp = 0;
	while (!exit)
	{
		line = get_next_line(fd);
		if (!line)
			exit = 1;
		else
		{
			if (checking(line, map))
				return (1);
		}
	}
	return (0);
}
