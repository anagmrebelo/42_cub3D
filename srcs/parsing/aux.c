/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:24:50 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 20:56:00 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

int	error_control(char *msj, int rtrn)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(msj, 1);
	return (rtrn);
}

int	save_ini_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->nb_rows)
	{
		j = -1;
		while (++j < map->nb_cols)
		{
			if (map->mtx[i][j] == 'N' || map->mtx[i][j] == 'S'
				|| map->mtx[i][j] == 'E' || map->mtx[i][j] == 'W')
			{
				map->view = map->mtx[i][j];
				map->px = j;
				map->py = i;
				if (check_round_2(map->mtx, i, j))
					return (error_control
						("Ini pos has to be surrounded by 1 or 0\n", 1));
			}
		}
	}
	return (0);
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

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*tab_to_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}
