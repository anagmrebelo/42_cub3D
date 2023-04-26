#include "cub3D.h"
#include "parsing.h"

int	check_color(char *str)
{
	char	**aux;
	int		n;
	int		i;

	aux = ft_split(str, ',');
	if (!aux)
		return (1); // que hago!!??
	i = 0;
	while (i < 3)
	{
		n = ft_atoi(aux[i]);
		if (n >= 0 && n <= 255)
			i++;
		else
		{
			free_tab(aux);
			return (1);
		}
	}
	free_tab(aux);
	return (0);
	
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
		return (NULL); //manejar en la otra funcion
	new = ft_strtrim(tab[1], "\n");
	// new = ft_strdup(tab[1]);
	if (!new)
	{
		free_tab(tab);
		return (NULL); //manejar en la otra funcion
	}
	free_tab(tab);
	return (new);
}