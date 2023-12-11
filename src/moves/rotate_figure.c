/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:49:20 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/11 18:16:13 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_sphere(t_sph *sph, t_matrix matrix);
void	rotate_light(t_light *light, t_matrix matrix);
void	rotate_plane(t_pl *plane, t_matrix matrix);

void	rotate_sphere(t_sph *sph, t_matrix matrix)
{
	sph->coord = multi_mat_vect(matrix, sph->coord);
}

void	rotate_plane(t_pl *plane, t_matrix matrix)
{
	plane->coord = multi_mat_vect(matrix, plane->coord);
	plane->n_coord = multi_mat_vect(matrix, plane->n_coord);
}

void	rotate_light(t_light *light, t_matrix matrix)
{
	light->coord = multi_mat_vect(matrix, light->coord);
}
