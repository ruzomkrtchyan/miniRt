/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:54:02 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/21 14:06:58 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cone	*init_cone(char **line);
t_cone	*init_cone_2(t_cone *tmp, char **vect, char **axis, char **colors);

t_cone	*init_cone(char **line)
{
	t_cone	*tmp;
	char	**colors;
	char	**vect;
	char	**axis;

	tmp = (t_cone *)malloc(sizeof(t_cone));
	if (!tmp)
		return (NULL);
	vect = ft_split(line[1], ',');
	axis = ft_split(line[2], ',');
	tmp->radius = ft_atof(line[3]) / 2;
	tmp->height = ft_atof(line[4]);
	tmp->degree = ft_atof(line[5]) / 2;
	tmp->spec = ft_atof(line[6]);
	colors = ft_split(line[7], ',');
	tmp = init_cone_2(tmp, vect, axis, colors);
	free_of_n(NULL, axis, colors, 3);
	free_2d(vect);
	return (tmp);
}

t_cone	*init_cone_2(t_cone *tmp, char **vect, char **axis, char **colors)
{
	tmp->color.r = ft_atoi(colors[0]);
	tmp->color.g = ft_atoi(colors[1]);
	tmp->color.b = ft_atoi(colors[2]);
	tmp->coord.x = ft_atof(vect[0]);
	tmp->coord.y = ft_atof(vect[1]);
	tmp->coord.z = ft_atof(vect[2]);
	tmp->coord.w = 1.0;
	tmp->axis.x = ft_atof(axis[0]);
	tmp->axis.y = ft_atof(axis[1]);
	tmp->axis.z = ft_atof(axis[2]);
	tmp->axis = norm_vect(tmp->axis);
	tmp->axis.w = 1.0;
	return (tmp);
}
