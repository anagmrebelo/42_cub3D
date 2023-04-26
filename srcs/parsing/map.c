/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:28 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/26 15:49:15 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"
# include "cub3D.h"

void free_tab(char** tab)
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

char **create_map(int x, int y)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc((x + 1), sizeof(char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < x)
	{
		map[i] = (char*)calloc(y + 1, sizeof(char));
		if (!map[i])
		{
			free_tab(map);
			return (NULL);
		}
		fill_with_spaces(map[i], y);
	}
	return (map);
}

void	fill_row(char *str, char *map_row)
{
	int	i;

	i = 0;
	while (str[i])
	{
		map_row[i] = str[i];
		i++;
	}
}

int fill_map(t_data *data)
{
	char	**aux;
	int		i;

	data->map = create_map(data->map_row, data->map_col);
	if (!data->map)
		return (1);
	aux = ft_split(data->str_map, '\n');
	if (!aux)
	{
		free_tab(data->map);
		return (1);
	}
	i = -1;
	while (++i < data->map_row)
		fill_row(aux[i], data->map[i]);
	if (check_map(data->map, data))
	{
		free_tab(data->map);
		free_tab(aux);
		return (1);
	}
	// printf("text_so: %s\ntext_no: %s\ntext_ea: %s\ntext_we: %s\n", data->tex_so, data->tex_no, data->tex_ea, data->tex_we);
	// printf("F: %s\nC: %s\n", data->color_f, data->color_c);
	free_tab(aux);
	return (0);
}