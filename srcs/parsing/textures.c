/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:16:16 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 14:46:48 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

static int	tex_check_name(char *str)
{
	if (ft_strcmp(str, "NO") != 0 && ft_strcmp(str, "SO") != 0
		&& ft_strcmp(str, "EA") != 0 && ft_strcmp(str, "WE") != 0)
	{
		error_control("Texture name not correct\n");
		return (1);
	}
	return (0);
}

static int	tex_len_check(char **tab)
{
	int	len;

	len = len_tab(tab);
	if (len > 2)
	{
		if ((ft_strcmp(tab[2], "\n") == 0) && (len == 3))
			return (0);
		error_control("Texture usage: <NO/SO/EA/WE ./path>\n");
		return (1);
	}
	return (0);
}

static char	*tex_parse(char *str)
{
	char	**tab;
	char	*new;

	str = tab_to_space(str);
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL);
	if (tex_len_check(tab) || tex_check_name(tab[0]))
	{
		free_tab(tab);
		return (NULL);
	}
	new = ft_strtrim(tab[1], "\n");
	if (!new)
	{
		free_tab(tab);
		error_control("Texture error\n");
		return (NULL);
	}
	free_tab(tab);
	return (new);
}

static char	*reassig_check(char *new, char *old)
{
	if (!old)
		return (new);
	else
	{
		free (new);
		free (old);
		return (NULL);
	}
}

int	tex_parse_aux(char a, char b, char *line, t_map *map)
{
	char	*texture;

	texture = tex_parse(line);
	if (!texture)
		return (2);
	if (a == 'N' && b == 'O')
		map->tex_no = reassig_check(texture, map->tex_no);
	if (a == 'S' && b == 'O')
		map->tex_so = reassig_check(texture, map->tex_so);
	if (a == 'E' && b == 'A')
		map->tex_ea = reassig_check(texture, map->tex_ea);
	if (a == 'W' && b == 'E')
		map->tex_we = reassig_check(texture, map->tex_we);
	return (0);
}
