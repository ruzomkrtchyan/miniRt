/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:00 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/19 15:29:56 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sph	*init_sp(char **line);

t_sph	*init_sp(char **line)
{
	t_sph	*tmp;
	char	**colors;
	char	**vect;

	tmp = (t_sph *)malloc(sizeof(t_sph));
	if (!tmp)
		return (NULL);
	vect = ft_split(line[1], ',');
	tmp->radius = ft_atof(line[2]) / 2;
	tmp->spec = ft_atof(line[3]);
	colors = ft_split(line[4], ',');
	tmp->coord.x = ft_atof(vect[0]);
	tmp->coord.y = ft_atof(vect[1]);
	tmp->coord.z = ft_atof(vect[2]);
	tmp->coord.w = 1.0;
	tmp->color.r = ft_atoi(colors[0]);
	tmp->color.g = ft_atoi(colors[1]);
	tmp->color.b = ft_atoi(colors[2]);
	tmp->chess = 0;
	if (line[5] && line[5][0] == '1')
		tmp->chess = 1;
	free_of_n(NULL, colors, vect, 2);
	return (tmp);
}
