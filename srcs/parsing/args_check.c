/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:45:11 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/15 14:48:50 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * Checks is file extension is .cub
 * Exits 1 if not
*/
static void	check_file_extension(char *file_name)
{
	int	i;

	i = ft_strlen(file_name) - 4;
	if (i <= 0)
	{
		printf("Insert a valid cub file.\n");
		exit(1);
	}
	if (ft_strncmp(&file_name[i], ".cub", 4) != 0)
	{
		printf("Insert a valid cub file.\n");
		exit(1);
	}
}

/**
 * Checks the program only receives one argument and that is a .cub file
 * Exits with 1 if not
*/
void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please insert one and only one cub file.\n");
		exit (1);
	}
	check_file_extension(argv[1]);
}