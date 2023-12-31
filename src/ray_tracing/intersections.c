/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:43 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/17 18:48:52 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	sphere_intersection(t_vect pos, t_vect ray, t_sph *sph)
{
	t_math	math;
	t_vect	cam_to_sphere;

	math.x1 = 0;
	cam_to_sphere = substract_v(pos, sph->coord);
	math.b = 2 * (dot_product_vect(cam_to_sphere, ray));
	math.c = dot_product_vect(cam_to_sphere, cam_to_sphere) \
		- (sph->radius * sph->radius);
	math.a = dot_product_vect(ray, ray);
	math.disc = (math.b * math.b) - (4 * math.a * math.c);
	if (math.disc < 0)
		return (0);
	math.x1 = ((-math.b) - sqrt(math.disc)) / (2 * math.a);
	if (math.x1 > 0)
		return (math.x1);
	return (0);
}

float	plane_inter(t_vect pos, t_vect ray, t_vect n_coord, t_vect coord)
{
	float	dot;
	float	t;

	dot = dot_product_vect(n_coord, ray);
	if (dot)
	{
		t = dot_product_vect(n_coord, \
			substract_v(coord, pos)) / dot;
		if (t >= 0.001)
			return (t);
	}
	return (INFINITY);
}

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
		else if (figure->type == CYLINDER)
			dot = cyl_inter(pos, ray, figure->cyl);
		else if (figure->type == PLANE)
			dot = plane_inter(pos, ray, figure->pl->n_coord, figure->pl->coord);
		else if (figure->type == CONE)
			dot = cone_inter(pos, ray, figure->cone);
		if (dot > 0.001 && dot < min_t)
		{
			min_t = dot;
			*tmp1 = figure;
		}
		figure = figure->next;
	}
	return (min_t);
}
