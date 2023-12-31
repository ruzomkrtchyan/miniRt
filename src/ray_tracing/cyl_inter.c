/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:40 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/06 21:37:28 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	calcul_dist(t_cyl *cyl, float t, t_vect ray, t_vect pos)
{
	float	dist;

	dist = dot_product_vect(cyl->n_coord, substract_v(num_product_vect(ray, t), \
			substract_v(cyl->cent, pos)));
	return (dist);
}

float	vect_proj(t_vect pos, t_vect ray, t_cyl *cyl, t_math *math)
{
	t_vect	ray_p;
	t_vect	oc_p;

	ray_p = num_product_vect(cyl->n_coord, dot_product_vect(ray, cyl->n_coord));
	ray_p = substract_v(ray, ray_p);
	oc_p = num_product_vect(cyl->n_coord, \
			dot_product_vect(substract_v(pos, cyl->cent), cyl->n_coord));
	oc_p = substract_v(substract_v(pos, cyl->cent), oc_p);
	math->a = dot_product_vect(ray_p, ray_p);
	math->b = 2 * dot_product_vect(ray_p, oc_p);
	math->c = dot_product_vect(oc_p, oc_p) - powf(cyl->radius, 2);
	math->disc = math->b * math->b - (4 * math->a * math->c);
	if (math->disc < 0)
		return (INFINITY);
	math->x1 = (-math->b - sqrt(math->disc)) / (2 * math->a);
	math->x2 = (-math->b + sqrt(math->disc)) / (2 * math->a);
	if (math->x1 < 0.001 && math->x2 < 0.001)
		return (INFINITY);
	return (1);
}

float	side_inter(t_vect pos, t_vect ray, t_cyl *cyl)
{
	t_math	math;

	if (vect_proj(pos, ray, cyl, &math) == INFINITY)
		return (INFINITY);
	cyl->dist[0] = calcul_dist(cyl, math.x1, ray, pos);
	cyl->dist[1] = calcul_dist(cyl, math.x2, ray, pos);
	if (!((cyl->dist[0] >= 0 && cyl->dist[0] <= cyl->height && math.x1 > 0.001) \
		|| (cyl->dist[1] >= 0 && cyl->dist[1] <= cyl->height \
			&& math.x2 > 0.001)))
		return (INFINITY);
	cyl->ray_norm = cylray_norm(&math, ray, pos, cyl);
	return (math.x1);
}

float	caps_inter(t_vect pos, t_vect ray, t_cyl *cyl)
{
	float	inter[2];
	t_vect	v[2];
	t_vect	center;

	center = sum_vect(cyl->cent, num_product_vect(cyl->n_coord, cyl->height));
	inter[0] = plane_inter(pos, ray, cyl->n_coord, center);
	inter[1] = plane_inter(pos, ray, cyl->n_coord, cyl->cent);
	if (inter[0] < INFINITY || inter[1] < INFINITY)
	{
		v[0] = sum_vect(pos, num_product_vect(ray, inter[0]));
		v[1] = sum_vect(pos, num_product_vect(ray, inter[1]));
		if ((inter[0] < INFINITY && dist_vect(v[0], center) <= cyl->radius) && \
			(inter[1] < INFINITY && dist_vect(v[1], cyl->cent) <= cyl->radius))
		{
			if (inter[0] > inter[1])
				return (inter[1]);
			return (inter[0]);
		}
		if (inter[0] < INFINITY && dist_vect(v[0], center) <= cyl->radius)
			return (inter[0]);
		if (inter[1] < INFINITY && dist_vect(v[1], cyl->cent) <= cyl->radius)
			return (inter[1]);
	}
	return (INFINITY);
}

float	cyl_inter(t_vect pos, t_vect ray, t_cyl *cyl)
{
	float	side_point;
	float	caps_point;

	side_point = side_inter(pos, ray, cyl);
	caps_point = caps_inter(pos, ray, cyl);
	if (side_point != INFINITY || caps_point != INFINITY)
	{
		if (side_point < caps_point)
			return (side_point);
		if (caps_point < INFINITY && caps_point > 0.001)
		{
			cyl->ray_norm = cyl->n_coord;
			if (cyl->n_coord.z <= 0)
				cyl->ray_norm = num_product_vect(cyl->n_coord, -1);
			return (caps_point);
		}
	}
	return (INFINITY);
}
