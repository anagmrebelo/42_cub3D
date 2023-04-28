/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:16:16 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/28 13:46:49 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

int	check_color(int *arr)
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

int	*color_arr(char *line)
{
	char	*str_color;
	char	**aux;
	int		*color;
	int		i;

	str_color = tex_parse(line);
	if (!str_color)
		return (NULL);
	aux = ft_split(str_color, ',');
	if (!aux)
	{
		free (str_color);
		return (NULL);
	}
	free (str_color);
	color = (int *)ft_calloc(4, sizeof(int));
	if (!color)
	{
		free_tab(aux);
		return (NULL);
	}
	i = -1;
	while (++i < 3)
		color[i] = ft_atoi(aux[i]);
	free_tab(aux);
	return (color);
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

char	*tex_parse(char *str)
{
	char	**tab;
	char	*new;

	str = tab_to_space(str);
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL);
	new = ft_strtrim(tab[1], "\n");
	if (!new)
	{
		free_tab(tab);
		return (NULL);
	}
	free_tab(tab);
	return (new);
}
