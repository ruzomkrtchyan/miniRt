/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:49:32 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/21 13:01:29 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	norm_cone(t_cone *cone, t_vect p, float t, t_scene *scene)
{
	t_vect	ray_norm;
	float	k;
	float	m;

	m = dot_product_vect(scene->ray, num_product_vect(cone->axis, t)) + \
		dot_product_vect(substract_v(scene->cam->pos, cone->coord), cone->axis);
	k = tan(cone->degree * M_PI / 180.0);
	ray_norm = norm_vect(substract_v(substract_v(p, cone->coord), \
				num_product_vect(cone->axis, ((1 + powf(k, 2))) * m)));
	return (ray_norm);
}

float	cone_inter2(t_vect ray, t_cone *cone, t_math math, t_vect oc)
{
	float	h1;
	float	h2;

	h1 = dot_product_vect(ray, cone->axis) * math.x1 + \
			dot_product_vect(oc, cone->axis);
	h2 = dot_product_vect(ray, cone->axis) * math.x2 + \
			dot_product_vect(oc, cone->axis);
	if (h1 > 0.001 && h1 <= cone->height && math.x1 > 0.001 \
		&& h2 > 0.001 && h2 <= cone->height && math.x1 > 0.001)
	{
		if (math.x1 < math.x2)
			return (math.x1);
		else
			return (math.x2);
	}
	if (h1 > 0.001 && h1 <= cone->height && math.x1 > 0.001)
		return (math.x1);
	else if (h2 > 0.001 && h2 <= cone->height && math.x1 > 0.001)
		return (math.x2);
	return (0);
}

float	cone_inter(t_vect pos, t_vect ray, t_cone *cone)
{
	t_vect	oc;
	t_math	math;
	float	k;

	k = tanf(cone->degree * M_PI / 180);
	oc = substract_v(pos, cone->coord);
	math.a = dot_product_vect(ray, ray) - (1 + powf(k, 2)) * \
				dot_product_vect(ray, cone->axis) * \
				dot_product_vect(ray, cone->axis);
	math.b = 2 * (dot_product_vect(ray, oc) - (1 + powf(k, 2)) * \
				dot_product_vect(ray, cone->axis) * \
				dot_product_vect(oc, cone->axis));
	math.c = dot_product_vect(oc, oc) - (1 + powf(k, 2)) * \
				dot_product_vect(oc, cone->axis) * \
				dot_product_vect(oc, cone->axis);
	math.disc = math.b * math.b - (4 * math.a * math.c);
	if (math.disc < 0)
		return (0);
	math.x1 = (-math.b + sqrt(math.disc)) / (2 * math.a);
	math.x2 = (-math.b - sqrt(math.disc)) / (2 * math.a);
	if (math.x1 < 0)
		return (0);
	return (cone_inter2(ray, cone, math, oc));
}
