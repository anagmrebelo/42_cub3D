/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:28 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/03 15:15:36 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
}

void	fill_with_spaces(char *str, int cols)
{
	int	i;

	i = -1;
	while (++i < cols)
		str[i] = ' ';
	str[i] = '\0';
}

char	**create_map(int x, int y)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc((x + 1), sizeof(char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < x)
	{
		map[i] = (char *)calloc(y + 1, sizeof(char));
		if (!map[i])
		{
			free_tab(map);
			return (NULL);
		}
		fill_with_spaces(map[i], y);
	}
	return (map);
}

void	fill_row(char *str, char *nb_rows)
{
	int	i;

	i = 0;
	while (str[i])
	{
		nb_rows[i] = str[i];
		i++;
	}
}

int	fill_map(t_map *map)
{
	char	**aux;
	int		i;

	map->mtx = create_map(map->nb_rows, map->nb_cols);
	if (!map->mtx)
		return (1);
	aux = ft_split(map->str_map, '\n');
	if (!aux)
	{
		free_tab(map->mtx);
		return (1);
	}
	i = -1;
	while (++i < map->nb_rows)
		fill_row(aux[i], map->mtx[i]);
	if (check_map(map->mtx, map))
	{
		free_tab(aux);
		return (1);
	}
	free_tab(aux);
	return (0);
}
