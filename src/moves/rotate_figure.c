/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:49:20 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/17 14:53:51 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_sphere(t_sph *sph, t_matrix matrix);
void	rotate_plane(t_pl *plane, t_matrix matrix);
void	rotate_light(t_light **light, t_matrix matrix);
void	rotate_cylinder(t_cyl *cylinder, t_matrix matrix);

void	rotate_sphere(t_sph *sph, t_matrix matrix)
{
	sph->coord = multi_mat_vect(matrix, sph->coord);
}

void	rotate_plane(t_pl *plane, t_matrix matrix)
{
	plane->coord = multi_mat_vect(matrix, plane->coord);
	plane->n_coord = multi_mat_vect(matrix, plane->n_coord);
}

void	rotate_cylinder(t_cyl *cylinder, t_matrix matrix)
{
	cylinder->cent = multi_mat_vect(matrix, cylinder->cent);
	cylinder->ray_norm = multi_mat_vect(matrix, cylinder->ray_norm);
	cylinder->n_coord = multi_mat_vect(matrix, cylinder->n_coord);
}

void	rotate_light(t_light **light, t_matrix matrix)
{
	t_light	*tmp;

	tmp = (*light);
	while (tmp)
	{
		tmp->coord = multi_mat_vect(matrix, tmp->coord);
		tmp = tmp->next;
	}
}
