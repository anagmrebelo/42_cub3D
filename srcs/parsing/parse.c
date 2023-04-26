/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:49:18 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/26 16:01:24 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
# include "parsing.h"

void	error_control(char *msj)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(msj, 1);
}

int	check_content(char *str_map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str_map[i])
	{
		if (str_map[i] == '0' || str_map[i] == '1'
			|| str_map[i] == ' ' || str_map[i] == '\n')
			i++;
		else if (str_map[i] == 'N' || str_map[i] == 'S'
			|| str_map[i] == 'W' || str_map[i] == 'E')
		{
			count++;
			i++;
		}
		else
		{
			error_control("Your map has a wrong character\n");
			printf("CHAR: %c\n", str_map[i]);
			return (1);
		}
	}
	if (count > 1)
	{
		error_control("Only 1 initial position\n");
		return (1);
	}
	return (0);
}

int	open_close(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	check_textures(t_data *data)
{
	if (!data->tex_ea || !data->tex_no || !data->tex_so || !data->tex_we)
		return (1);
	// if (open_close(data->tex_ea)|| open_close(data->tex_no)
	// 	|| open_close(data->tex_so) || open_close(data->tex_we))
	// {
	// 	printf("no abre el archivo\n");
	// 	return (1);
	// }
	return (0);
}

int parse(char *path, t_data *data)
{
	data->str_map = read_file(path, data);
	if (!data->str_map)
		return (1);
	if (check_content(data->str_map))
		return (1);
	if (check_textures(data))
	{
		free (data->str_map);
		return (1);
	}
	if (fill_map(data))
		return (1);
	return (0);
}