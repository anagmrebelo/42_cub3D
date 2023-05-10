/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:44:32 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 14:50:58 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

static int	check_color(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] >= 0 && arr[i] <= 255)
			i++;
		else
			return (1);
	}
	return (0);
}

static int	*fill_color_array(char **tab)
{
	int	*color;
	int	len;
	int	i;

	len = len_tab(tab);
	if (len != 3)
	{
		free_tab (tab);
		return (NULL);
	}
	color = (int *)ft_calloc(len + 1, sizeof(int));
	if (!color)
	{
		free_tab(tab);
		return (NULL);
	}
	i = -1;
	while (tab[++i])
		color[i] = ft_atoi(tab[i]);
	return (color);
}

int	p_color_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] == ',')
			return (1);
		i++;
	}
	return (0);
}

static int	*parse_color_array(char *line)
{
	char	**tab;
	int		*color;
	char	*clean;

	line = tab_to_space(line);
	if (p_color_check(line))
		return (NULL);
	clean = clean_color(line);
	if (!clean)
		return (NULL);
	tab = ft_split(clean, ',');
	if (!tab)
	{
		free (clean);
		return (NULL);
	}
	free(clean);
	color = fill_color_array(tab);
	if (!color)
		return (NULL);
	free_tab(tab);
	return (color);
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
