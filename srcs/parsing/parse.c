/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:49:18 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 20:39:34 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

static int	aux_check_content(int count)
{
	if (count > 1)
		return (error_control("Only 1 initial position\n", 1));
	if (count == 0)
		return (error_control("You need an initial position: N-W-E-S\n", 1));
	return (0);
}

static int	check_content(char *str_map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str_map[i])
	{
		if (str_map[i] == '0' || str_map[i] == '1'
			|| str_map[i] == ' ' || str_map[i] == '\n')
			i++;
		else if (str_map[i] == 'N' || str_map[i] == 'S'
			|| str_map[i] == 'W' || str_map[i] == 'E')
		{
			count++;
			i++;
		}
		else
			return (error_control("Your map has a wrong character\n", 1));
	}
	if (aux_check_content(count))
		return (1);
	return (0);
}

static int	open_close(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

static int	check_textures(t_map *map)
{
	if (!map->tex_ea || !map->tex_no || !map->tex_so || !map->tex_we)
		return (error_control("Texture error or missing\n", 1));
	if (open_close(map->tex_ea) || open_close(map->tex_no)
		|| open_close(map->tex_so) || open_close(map->tex_we))
		return (error_control("Can't open texture\n", 1));
	return (0);
}

int	parse(char *path, t_map *map)
{
	map->str_map = NULL;
	map->nb_cols = 0;
	map->nb_rows = 0;
	if (read_file(path, map))
		return (1);
	if (!map->str_map)
		return (error_control("No map in the file\n", 1));
	if (!map->color_c || !map->color_f)
		return (error_control("Missing color\n", 1));
	if (check_content(map->str_map))
		return (1);
	if (check_textures(map))
		return (1);
	if (fill_map(map))
		return (1);
	if (save_ini_pos(map))
		return (1);
	return (0);
}
