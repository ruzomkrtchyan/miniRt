#include "minirt.h"

t_light	*fill_light(char **line);

t_light	*fill_light(char **line)
{
	t_light	*tmp;
	char	**colors;
	char	**vect;

	tmp = (t_light *)malloc(sizeof(t_light));
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	tmp->coord = (t_vect *)malloc(sizeof(t_vect));
	if (!tmp || !tmp->color || !tmp->coord)
		return (NULL);
	vect = ft_split(line[1], ',');
	colors = ft_split(line[2], ',');
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->coord->x = ft_atof(vect[0]);
	tmp->coord->y = ft_atof(vect[1]);
	tmp->coord->z = ft_atof(vect[2]);
	tmp->bright = ft_atof(line[3]);
	free_of_n(NULL, colors, vect, 2);
	return (tmp);
}
