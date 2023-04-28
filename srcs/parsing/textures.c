/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:16:16 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/28 17:46:03 by mrollo           ###   ########.fr       */
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
	printf("str_color: %s\n", str_color);
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
	while (++i < 4)
	{
		printf("aux[%d]: %s\n", i, aux[i]);
		color[i] = ft_atoi(aux[i]);
		printf("color[%d]: %d\n", i, color[i]);
	}
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

// int	check_number(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		printf("c: [%c]\n", str[i]);
// 		if (ft_isdigit(str[i]))
// 			i++;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

// char	*color_trim(char *str)
// {
// 	int	len;
// 	char	*color;

// 	len = ft_strlen(str);
// 	if (str[len - 1] == ',')
// 		color = ft_strtrim(str, ",");
// 	if (str[len - 1] == '\n')
// 		color = ft_strtrim(str, "\n");
// 	return (color);
// }

char	*clean_color(char *str)
{
	int	i;
	int	count;
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
	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ',')
		{
			color[count] = str[i];
			i++;
			count++;		
		}
		else
			i++;
	}
	return (color);
}

int	*parse_color_array(char *line)
{
	char	**tab;
	int		*color;
	int		i;
	char	*str;
	char	*clean;

	line = tab_to_space(line);
	// printf("line: %s\n", line);
	clean = clean_color(line);
	printf("clean_line: [%s]\n", clean);
	tab = ft_split(line, ' ');
	if (!tab)
		return (NULL);
	color = (int *)ft_calloc(4, sizeof(int));
	i = 0;
	while (tab[++i])
	{
		str = ft_strtrim(tab[i], ",");
		// if (check_number(str))
		// 	return (NULL);
		color[i] = ft_atoi(str);
		free (str);
	}
	free_tab(tab);
	return (color);
}