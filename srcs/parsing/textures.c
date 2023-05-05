/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:16:16 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/05 12:45:47 by mrollo           ###   ########.fr       */
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

// int	*color_arr(char *line)
// {
// 	char	*str_color;
// 	char	**aux;
// 	int		*color;
// 	int		i;

// 	str_color = tex_parse(line);
// 	if (!str_color)
// 		return (NULL);
// 	aux = ft_split(str_color, ',');
// 	if (!aux)
// 	{
// 		free (str_color);
// 		return (NULL);
// 	}
// 	free (str_color);
// 	color = (int *)ft_calloc(4, sizeof(int));
// 	if (!color)
// 	{
// 		free_tab(aux);
// 		return (NULL);
// 	}
// 	i = -1;
// 	while (++i < 4)
// 		color[i] = ft_atoi(aux[i]);
// 	free_tab(aux);
// 	return (color);
// }

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

char	*fill_clean_color(char *color, char *str, int i, int count)
{
	// int		i;
	// int		count;

	// i = 0;
	// count = -1;
	printf("count: %d, i: %d\n", count, i);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] == 'F' || str[i] == 'C')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
			i++;
		else if ((str[i] > 47 && str[i] < 58) || str[i] == ',')
		{
			color[++count] = str[i];
			i++;
		}
		else if (str[i] == '\n')
			i++;
		else
		{
			free(color);
			return (NULL);
		}
	}
	return (color);
}

char	*aux_clean_color(char *str)
{
	int		i;
	int		count;
	char	*color;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ',')
			count++;
		i++;
	}
	color = (char *)ft_calloc(count + 1, sizeof(char));
	if (!color)
		return (NULL);
	color = fill_clean_color(color, str, 0, -1);
	if (!color)
		return (NULL);
	return (color);
}

char	*clean_color(char *str)
{
	// int		i;
	// int		count;
	char	*color;

	color = aux_clean_color(str);
	// i = 0;
	// count = 0;
	// while (str[i])
	// {
	// 	while (str[i] == ' ' || str[i] == '\t')
	// 		i++;
	// 	if ((str[i] == 'F' || str[i] == 'C')
	// 		&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
	// 		i++;
	// 	else if ((str[i] > 47 && str[i] < 58) || str[i] == ',')
	// 	{
	// 		color[count] = str[i];
	// 		i++;
	// 		count++;
	// 	}
	// 	else if (str[i] == '\n')
	// 		i++;
	// 	else
	// 	{
	// 		free(color);
	// 		return (NULL);
	// 	}
	// }
	if (ft_strlen(color) < 1)
	{
		free(color);
		return (NULL);
	}
	return (color);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*parse_color_array(char *line)
{
	char	**tab;
	int		*color;
	int		i;
	char	*clean;
	int		len;

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
	len = len_tab(tab);
	if (len != 3)
		return (NULL);
	color = (int *)ft_calloc(len + 1, sizeof(int));
	if (!color)
	{
		free (clean);
		free_tab(tab);
		return (NULL);
	}
	i = -1;
	while (tab[++i])
		color[i] = ft_atoi(tab[i]);
	free_tab(tab);
	return (color);
}
