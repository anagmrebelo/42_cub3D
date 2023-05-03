/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:46:05 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/28 16:10:54 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdio.h>
# include "cub3D.h"

void	check_args(int argc, char **argv, t_master *master);
int		parse(char *path, t_map *map);
char	*read_file(char *path, t_map *map);
char	**create_map(int x, int y);
int		fill_map(t_map *map);
int		check_map(char **mtx, t_map *map);
char	*tex_parse(char *str);
int		*color_arr(char *line);
int	    *parse_color_array(char *str);
int		check_color(int *arr);
void	free_tab(char** tab);
void	error_control(char *msj);

#endif