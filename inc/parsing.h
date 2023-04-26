/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:46:05 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/26 15:47:54 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <libft.h>
# include <stdio.h>
# include "cub3D.h"

void	check_args(int argc, char **argv, t_master *master);
int		parse(char *path, t_data *data);
char	*read_file(char *path, t_data *data);
char	**create_map(int x, int y);
int		fill_map(t_data *data);
int		check_map(char **map, t_data *data);
char	*tex_parse(char *str);
int		check_color(char *str);
void	free_tab(char** tab);

#endif