/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:55:52 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/17 16:50:03 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
# include "get_next_line.h"

char	*read_file(char *path)
{
    int     fd;
    char    *line;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("no puedo abrir\n");
        return (NULL);
    }
    line = get_next_line(fd);
    printf("%s\n", line);
    return (NULL);
}