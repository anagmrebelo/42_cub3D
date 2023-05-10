/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:31:04 by mrollo            #+#    #+#             */
/*   Updated: 2023/05/10 14:33:54 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

static char	*fill_clean_color(char *color, char *str, int i, int count)
{
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

static char	*aux_clean_color(char *str)
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
	char	*color;

	color = aux_clean_color(str);
	if (ft_strlen(color) < 1)
	{
		free(color);
		return (NULL);
	}
	return (color);
}
