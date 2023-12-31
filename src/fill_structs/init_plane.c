/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:03 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/21 14:06:49 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pl	*init_pl(char **line);
void	init_pl_2(char **n_vect, t_pl *tmp);

t_pl	*init_pl(char **line)
{
	t_pl	*tmp;
	char	**colors;
	char	**vect;
	char	**n_vect;

	tmp = (t_pl *)malloc(sizeof(t_pl));
	if (!tmp)
		return (NULL);
	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	tmp->spec = ft_atof(line[3]);
	colors = ft_split(line[4], ',');
	tmp->color.r = ft_atoi(colors[0]);
	tmp->color.g = ft_atoi(colors[1]);
	tmp->color.b = ft_atoi(colors[2]);
	tmp->coord.x = ft_atof(vect[0]);
	tmp->coord.y = ft_atof(vect[1]);
	tmp->coord.z = ft_atof(vect[2]);
	tmp->coord.w = 1.0;
	init_pl_2(n_vect, tmp);
	free_of_n(NULL, n_vect, colors, 3);
	free_2d(vect);
	return (tmp);
}

void	init_pl_2(char **n_vect, t_pl *tmp)
{
	tmp->n_coord.x = ft_atof(n_vect[0]);
	tmp->n_coord.y = ft_atof(n_vect[1]);
	tmp->n_coord.z = ft_atof(n_vect[2]);
	tmp->n_coord = norm_vect(tmp->n_coord);
	tmp->n_coord.w = 1.0;
	if (tmp->n_coord.x > 0.0)
		tmp->n_coord.x *= -1;
	if (tmp->n_coord.y > 0.0)
		tmp->n_coord.y *= -1;
}
