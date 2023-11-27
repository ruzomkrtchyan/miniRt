/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:10 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/27 15:30:57 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cyl	*init_cyl(char **line);
t_cyl	*init_cyl_2(t_cyl *tmp, char **vect, char **n_vect, char **colors);

t_cyl	*init_cyl(char **line)
{
	t_cyl	*tmp;
	char	**colors;
	char	**vect;
	char	**n_vect;

	tmp = (t_cyl *)malloc(sizeof(t_cyl));
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	if (!tmp || !tmp->color)
		return (NULL);
	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	tmp->radius = ft_atof(line[3]) / 2;
	tmp->height = ft_atof(line[4]);
	tmp->spec = ft_atof(line[5]);
	colors = ft_split(line[6], ',');
	tmp = init_cyl_2(tmp, vect, n_vect, colors);
	free_of_n(NULL, n_vect, colors, 3);
	free_2d(vect);
	return (tmp);
}

t_cyl	*init_cyl_2(t_cyl *tmp, char **vect, char **n_vect, char **colors)
{
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->coord.x = ft_atof(vect[0]);
	tmp->coord.y = ft_atof(vect[1]);
	tmp->coord.z = ft_atof(vect[2]);
	tmp->coord.w = 1.0;
	tmp->n_coord.x = ft_atof(n_vect[0]);
	tmp->n_coord.y = ft_atof(n_vect[1]);
	tmp->n_coord.z = ft_atof(n_vect[2]);
	tmp->n_coord.w = 1.0;
	if (tmp->n_coord.x > 0.0)
		tmp->n_coord.x *= -1;
	if (tmp->n_coord.y > 0.0)
		tmp->n_coord.y *= -1;
	return (tmp);
}
