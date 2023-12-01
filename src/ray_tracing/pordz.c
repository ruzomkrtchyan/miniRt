/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pordz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:12:29 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/01 15:38:42 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

// t_vec	calc_cylinder_normal(float t[2], t_vect vecs[2], t_cyl *cylinder)
// {
// 	float	dist;

// 	dist = choose_cylinder_dist(t, cylinder);
// 	return (ft_vec_norm(ft_vec_substr(ft_vec_substr(ft_vec_mult(vecs[0], t[0]),
// 					ft_vec_mult(cylinder->direction, dist)),
// 				ft_vec_substr(cylinder->center, vecs[1]))));
// }

// float	calc_cylinder_dist(t_cyl *cylinder, t_vect vecs[2], float t)
// {
// 	float	dist;

// 	dist = ft_vec_mult_dot(cylinder->direction,
// 			ft_vec_substr(ft_vec_mult(vecs[0], t),
// 				ft_vec_substr(cylinder->center, vecs[1])));
// 	return (dist);
// }

// float	calc_side_inter(t_vect vecs[2], t_vect *normal, t_cyl *cylinder)
// {
// 	float	t[2];

// 	if (quadratic_cylinder(t, vecs, cylinder) == 0)
// 		return (INFINITY);
// 	cylinder->dist[0] = calc_cylinder_dist(cylinder, vecs, t[0]);
// 	cylinder->dist[1] = calc_cylinder_dist(cylinder, vecs, t[1]);
// 	if (!((cylinder->dist[0] >= 0 && cylinder->dist[0] <= cylinder->height
// 				&& t[0] > EPSILON)
// 			|| (cylinder->dist[1] >= 0 && cylinder->dist[1] <= cylinder->height
// 				&& t[0] > EPSILON)))
// 		return (INFINITY);
// 	*normal = calc_cylinder_normal(t, vecs, cylinder);
// 	return (t[0]);
// }

// float	calc_caps_inter(t_vect vecs[2], t_cyl *cy)
// {
// 	float	inter[2];
// 	t_vect	v[2];
// 	t_vect	center;

// 	center = sum_vect(cy->cent, ft_vec_mult(cy->direction, cy->height));
// 	inter[0] = plane_inter(vecs[1], vecs[0], cy->center, cy->direction);
// 	inter[1] = plane_inter(vecs[1], vecs[0], center, cy->direction);
// 	if (inter[0] < INFINITY || inter[1] < INFINITY)
// 	{
// 		v[0] = ft_vec_add(vecs[1], ft_vec_mult(vecs[0], inter[0]));
// 		v[1] = ft_vec_add(vecs[1], ft_vec_mult(vecs[0], inter[1]));
// 		if ((inter[0] < INFINITY && ft_vec_dist(v[0], cy->center) <= cy->radius)
// 			&& (inter[1] < INFINITY && ft_vec_dist(v[1], center) <= cy->radius))
// 		{
// 			if (inter[0] < inter[1])
// 				return (inter[0]);
// 			return (inter[1]);
// 		}
// 		if (inter[0] < INFINITY && ft_vec_dist(v[0], cy->center) <= cy->radius)
// 			return (inter[0]);
// 		if (inter[1] < INFINITY && ft_vec_dist(v[1], center) <= cy->radius)
// 			return (inter[1]);
// 		return (INFINITY);
// 	}
// 	return (INFINITY);
// }

// float	cylinder_inter(t_vect o, t_vect d, t_figure *figure)
// {
// 	float	side_inter;
// 	float	caps_inter;
// 	t_vect	vecs[2];
// 	t_vect	normal;

// 	vecs[0] = d;
// 	vecs[1] = o;
// 	side_inter = calc_side_inter(vecs, &normal, figure->cyl);
// 	caps_inter = calc_caps_inter(vecs, figure->cyl);
// 	if (side_inter < INFINITY || caps_inter < INFINITY)
// 	{
// 		if (side_inter < caps_inter && side_inter > EPSILON)
// 		{
// 			figure->cyl->ray_norm = normal;
// 			return (side_inter);
// 		}
// 		if (caps_inter < INFINITY && caps_inter > EPSILON)
// 		{
// 			figure->cyl->ray_norm = figure->cyl->n_coord;
// 			if (figure->cyl->n_coord.z <= 0)
// 				figure->cyl->ray_norm = num_product_vect(figure->cyl->ray_norm, -1);
// 			return (caps_inter);
// 		}
// 	}
// 	return (INFINITY);
// }