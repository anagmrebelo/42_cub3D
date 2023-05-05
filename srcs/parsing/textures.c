/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:16:16 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/05 13:35:00 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

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

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*fill_color_array(char **tab)
{
	int	*color;
	int	len;
	int	i;

	len = len_tab(tab);
	if (len != 3)
		return (NULL);
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

int	*parse_color_array(char *line)
{
	char	**tab;
	int		*color;
	char	*clean;

	line = tab_to_space(line);
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
