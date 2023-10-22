#include "minirt.h"

t_amb	*fill_amb(char **line);

t_amb	*fill_amb(char **line)
{
	t_amb	*tmp;
	char	**colors;

	tmp = (t_amb *)malloc(sizeof(t_amb));
	if (!tmp)
		return (NULL);
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	colors = ft_split(line[2], ',');
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->ratio = ft_atof(line[2]);
	free_2d(colors);
	return (tmp);
}
