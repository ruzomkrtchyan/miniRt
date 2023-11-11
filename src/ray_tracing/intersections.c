/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:43 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/11 18:26:32 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	sphere_intersection(t_vect pos, t_vect ray, t_sph *sph)
{
	float	b;
	float	c;
	float	disc;
	float	x1;
	float	a;
	t_vect	cam_to_sphere;

	x1 = 0;
	cam_to_sphere = substraction_vect(pos, sph->coord);
	b = 2 * (dot_product_vect(cam_to_sphere, ray));
	c = dot_product_vect(cam_to_sphere, cam_to_sphere) \
		- (sph->radius * sph->radius);
	a = dot_product_vect(ray, ray);
	disc = (b * b) - (4 * a * c);
	if (disc < 0)
		return (0);
	x1 = ((-b) - sqrt(disc)) / (2 * a);
	if (x1 > 0)
		return (x1);
	return (0);
}

// float	plane_inter()
// {
	
// }

float	closest_inter(t_vect pos, t_vect ray, t_figure *figure, t_figure **tmp1)
{
	float	min_t;
	float	dot;

	min_t = INFINITY;
	dot = INFINITY;
	while (figure)
	{
		if (figure->type == SPHERE)
			dot = sphere_intersection(pos, ray, figure->sph);
		// else if (figure->type == PLANE)
		// 	dot = plane_inter();
		if (dot && dot < min_t)
		{
			min_t = dot;
			*tmp1 = figure;
		}
		figure = figure->next;
	}
	return (min_t);
}
