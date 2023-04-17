/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:34:38 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/17 16:45:39 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_line(char *save)
{
	char	*temp;
	char	*aux;
	int		len;

	aux = ft_strchr(save, '\n');
	if (!aux)
	{
		free(save);
		temp = NULL;
		return (NULL);
	}
	else
		len = (aux - save) + 1;
	if (!save[len])
	{
		free(save);
		return (NULL);
	}
	temp = ft_substr(save, len, ft_strlen(save) - len);
	free(save);
	return (temp);
}

char	*get_new_line(char *save)
{
	int		len;
	char	*aux;
	char	*line;

	aux = ft_strchr(save, '\n');
	len = (aux - save) + 1;
	line = ft_substr(save, 0, len);
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *save)
{
	int		n;
	char	*buffer;

	n = 1;
	buffer = ft_calloc(1 + 1, sizeof(char));
	while (n > 0 && (ft_strchr(buffer, '\n') == NULL))
	{
		n = read(fd, buffer, 1);
		if (n == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (n > 0)
		{
			buffer[n] = '\0';
			save = ft_strjoin(save, buffer);
		}
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0)
		return (NULL);
	if ((save && !ft_strchr(save, '\n')) || !save)
		save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = get_new_line(save);
	if (!line)
	{
		return (NULL);
		free(save);
	}
	save = clean_line(save);
	return (line);
}
