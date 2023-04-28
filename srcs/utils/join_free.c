/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:16:34 by mrollo            #+#    #+#             */
/*   Updated: 2023/04/28 12:27:18 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*free_aux_join(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (NULL);
}

char	*join_free_s1(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new || !s1)
		return (free_aux_join(new, s1, NULL));
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	if (!s2)
	{
		free(s1);
		return (new);
	}
	while (s2[++j])
		new[i + j] = s2[j];
	free(s1);
	return (new);
}

char	*join_double_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (free_aux_join(s1, s2, NULL));
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		new[i + j] = s2[j];
	free(s1);
	if (s2)
		free(s2);
	return (new);
}