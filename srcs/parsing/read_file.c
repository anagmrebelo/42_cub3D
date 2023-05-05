/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:55:52 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/05 13:28:53 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "parsing.h"
#include "utils.h"

void	tex_parse_aux(char a, char b, char *line, t_map *map)
{
	if (a == 'N' && b == 'O')
		map->tex_no = tex_parse(line);
	if (a == 'S' && b == 'O')
		map->tex_so = tex_parse(line);
	if (a == 'E' && b == 'A')
		map->tex_ea = tex_parse(line);
	if (a == 'W' && b == 'E')
		map->tex_we = tex_parse(line);
}

int	aux_check_line(char a, char b, char *line, t_map *map)
{
	if ((a == 'N' && b == 'O') || (a == 'S' && b == 'O')
		|| (a == 'E' && b == 'A') || (a == 'W' && b == 'E'))
	{
		tex_parse_aux(a, b, line, map);
		return (1);
	}
	if (a == 'C' || a == 'F')
	{
		if (color_parse(line, a, map))
		{
			error_control("Color not valid or missing color\n");
			return (2);
		}
		return (1);
	}
	else
	{
		error_control("Shit on the .cub\n");
		return (2);
	}
}

int	check_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (!ft_isspace(line))
		return (1);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] > 64 && line[i] < 91)
			return (aux_check_line(line[i], line[i + 1], line, map));
		if (line[i] == '1')
			return (0);
		else
		{
			error_control("Shit on the .cub\n");
			return (2);
		}
	}
	return (0);
}

int	checking(char *line, t_map *map)
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
