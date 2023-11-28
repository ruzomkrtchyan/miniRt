// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cyl_inter.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/11/27 15:35:40 by rmkrtchy          #+#    #+#             */
// /*   Updated: 2023/11/28 16:15:47 by rmkrtchy         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minirt.h"

// // float	vect_proj(t_vect pos, t_vect ray, t_cyl *cyl, t_math *math)
// // {
// // 	t_math	math;
// // 	float	proj[2];
// // 	t_vect	p1;
// // 	t_vect	p2;
// // 	t_vect	x;

// // 	x = substraction_vect(pos, cyl->coord);
// // 	math.a = dot_product_vect(ray, ray) - powf(dot_product_vect(ray, cyl->n_coord), 2);
// // 	math.b = 2 * (dot_product_vect(ray, x) - (dot_product_vect(ray, cyl->n_coord) * dot_product_vect(x, cyl->n_coord)));
// // 	math.c = dot_product_vect(x, x) - powf(dot_product_vect(x, cyl->n_coord), 2) - powf(cyl->radius, 2);
// // 	math.disc = math.b * math.b - (4 * math.a * math.c);
// // 	if (math.disc > 0)
// // 	{
// // 		math->x1 = -math->b - sqrt(math->disc)	/ 2 * math->a;
// // 		math->x2 = -math->b + sqrt(math->disc)	/ 2 * math->a;
// // 		return (1);
// // 	}
// // 	return (0);
// // }

// float	calcul_dist(t_cyl *cyl, t_math *math, t_vect ray, t_vect pos)
// {
// 	float	dist;

// 	dist = dot_product_vect(cyl->n_coord, \
// 			substraction_vect(num_product_vect(math->x1, ray), \
// 			substraction_vect(cyl->coord, pos)));
// 	return (dist);
// }

// float	vect_proj(t_vect pos, t_vect ray, t_cyl *cyl, t_math *math)
// {
// 	t_vect	ray_p;
// 	t_vect	oc_p;

// 	ray_p = num_product_vect(cyl->n_coord, dot_product_vect(ray, cyl->n_coord));
// 	ray_p = substraction_vect(ray, ray_p);
// 	oc_p = num_product_vect(cyl->n_coord, \
// 			dot_product_vect(substraction_vect(pos, cyl->coord), cyl->n_coord));
// 	oc_p = substraction_vect(substraction_vect(pos, cyl->coord), oc_p);
// 	math->a = dot_product_vect(ray_p, ray_p);
// 	math->b = 2 * dot_product_vect(ray_p, oc_p);
// 	math->c = dot_product_vect(oc_p, oc_p) - powf(cyl->radius, 2);
// 	math->disc = math->b * math->b - 4 * math->a * math->c;
// 	if (math->disc > 0)
// 	{
// 		math->x1 = -math->b - sqrt(math->disc) / 2 * math->a;
// 		math->x2 = -math->b + sqrt(math->disc) / 2 * math->a;
// 		return (1);
// 	}
// 	return (0);
// }

// float	side_inter(t_vect pos, t_vect ray, t_cyl *cyl)
// {
// 	t_math	math;
// 	float	dist[2];

// 	if (vect_proj(pos, ray, cyl, &math) == 0)
// 		return (0);
// 	dist[0] = calcul_dist(cyl, &math, ray, pos);
// 	dist[1] = calcul_dist(cyl, &math, ray, pos);
// 	if (dist[0] < 0 || dist[0] > cyl->height || math.x1 < 0.001 \
// 		|| dist[1] < 0 || dist[0] > cyl->height || math.x2 < 0.001)
// 		return (0);
// 	return (math.x1);
// }

// float	caps_inter(t_vect pos, t_vect ray, t_cyl *cyl)
// {
// 	t_pl	*plane;
// 	float	inter[2];
// 	t_vect	vect[2];
// 	t_vect	center;

// 	center = sum_vect(cyl->coord, num_product_vect(cyl->n_coord, cyl->height));
// 	plane->coord = center;
// 	plane->n_coord = cyl->n_coord;
// 	inter[0] = plane_inter(pos, ray, plane);
// 	plane->coord = cyl->coord;
// 	inter[1] = plane_inter(pos, ray, plane);
// 	if (inter[0] < INFINITY || inter[1] < INFINITY)
// 	{
// 		vect[0] = sum_vect(pos, num_product_vect(ray, inter[0]));
// 		vect[1] = sum_vect(pos, num_product_vect(ray, inter[1]));
// 		if (dist_vect(v[0], cyl->coord) <= cyl->radius && \
// 				dist_vect(v[1], center) <= cyl->radius)
// 		{
// 			if (inter[0] > inter[1])
// 				return (inter[1]);
// 			return (inter[0]);
// 		}
// 		if (dist_vect(v[0], cyl->coord) <= cyl->radius)
// 			return (inter[0]);
// 		if (dist_vect(v[1], center) <= cyl->radius)
// 			return (inter[1]);
// 	}
// 	return (0);
// }

// float	cyl_inter(t_vect pos, t_vect ray, t_cyl *cyl)
// {
// 	float	side_point;
// 	float	caps_point;

// 	side_point = side_inter(pos, ray, cyl);
// 	caps_point = caps_inter(pos, ray, cyl);
// }
