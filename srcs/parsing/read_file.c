/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:55:52 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/03 15:16:16 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include "parsing.h"
#include "utils.h"

int	count_row(char *str_map)
{
	int	count;
	int	nb_rows;

	count = 0;
	nb_rows = 0;
	while (str_map[count])
	{
		if (str_map[count] != '\n')
			count++;
		else
		{
			nb_rows++;
			count++;
		}
	}
	return (nb_rows);
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

int	color_parse(char *line, char a, t_map *map)
{
	if (a == 'C')
	{
		map->color_c = parse_color_array(line);
		if (!map->color_c)
			return (1);
		if (check_color(map->color_c))
		{
			// free (map->color_c);
			return (1);
		}
	}
	if (a == 'F')
	{
		map->color_f = parse_color_array(line);
		if (!map->color_f)
			return (1);
		if (check_color(map->color_f))
		{
			// free (map->color_f);
			return (1);
		}
	}
	return (0);
}

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

int	check_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (!ft_isspace(line))
		return (1);
	while (line)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if ((line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O')
			|| (line[i] == 'E' && line[i + 1] == 'A')
			|| (line[i] == 'W' && line[i + 1] == 'E'))
		{
			tex_parse_aux(line[i], line[i + 1], line, map);
			return (1);
		}
		if (line[i] == 'C' || line[i] == 'F')
		{
			if (color_parse(line, line[i], map))
			{
				error_control("Color not valid or missing color\n");
				return (2);
			}
			return (1);
		}
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

char	*read_file(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int		exit;
	char	*str_map;
	int		len;
	int		chk;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_control("Cannot read the map\n");
		return (NULL);
	}
	line = NULL;
	exit = 0;
	map->nb_cols = 0;
	str_map = NULL;
	while (!exit)
	{
		line = get_next_line(fd);
		if (!line)
			exit = 1;
		else
		{
			chk = check_line(line, map);
			if (chk == 1)
				free (line);
			else if (chk == 2)
			{
				free (line);
				return (NULL);
			}
			else
			{
				len = ft_strlen(line) - 1;
				if (len > map->nb_cols)
					map->nb_cols = len;
				str_map = join_free_s1(str_map, line);
				free (line);
			}
		}
	}
	if (!str_map)
	{
		error_control("No map in the file\n");
		return (NULL);
	}
	map->nb_rows = count_row(str_map);
	return (str_map);
}
