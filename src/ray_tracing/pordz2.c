/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pordz2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:14:55 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/01 15:38:52 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

// void	quadratic_vecs(t_vect *pv1, t_vect *pv2, t_cyl *cy, t_vect vecs[2])
// {
// 	t_vect	v1;
// 	t_vect	v2;

// 	v1 = ft_vec_mult(cy->direction, ft_vec_mult_dot(vecs[0], cy->direction));
// 	v1 = ft_vec_substr(vecs[0], v1);
// 	v2 = ft_vec_mult(cy->direction,
// 			ft_vec_mult_dot(ft_vec_substr(vecs[1], cy->center), cy->direction));
// 	v2 = ft_vec_substr(ft_vec_substr(vecs[1], cy->center), v2);
// 	*pv1 = v1;
// 	*pv2 = v2;
// }

// int	quadratic_cylinder(float t[2], t_vect vecs[2], t_cyl *cy)
// {
// 	t_vect	v1;
// 	t_vect	v2;
// 	t_math	abc;

// 	quadratic_vecs(&v1, &v2, cy, vecs);
// 	abc.a = ft_vec_mult_dot(v1, v1);
// 	abc.b = 2 * ft_vec_mult_dot(v1, v2);
// 	abc.c = ft_vec_mult_dot(v2, v2) - pow(cy->radius, 2);
// 	abc.disc = abc.b * abc.b - (4 * abc.a * abc.c);
// 	if (abc.disc < 0)
// 	{
// 		t[0] = INFINITY;
// 		t[1] = INFINITY;
// 		return (0);
// 	}
// 	t[0] = (-abc.b + sqrt(abc.disc)) / (2 * abc.a);
// 	t[1] = (-abc.b - sqrt(abc.disc)) / (2 * abc.a);
// 	if (t[0] < EPSILON && t[1] < EPSILON)
// 	{
// 		t[0] = INFINITY;
// 		t[1] = INFINITY;
// 		return (0);
// 	}
// 	return (1);
// }

// float	choose_cylinder_dist(float t[2], t_cyl *cy)
// {
// 	float	dist;
// 	float	t1;

// 	if ((cy->dist[0] >= 0 && cy->dist[0] <= cy->height && t[0] > EPSILON)
// 		&& (cy->dist[1] >= 0 && cy->dist[1] <= cy->height && t[1] > EPSILON))
// 	{
// 		dist = cy->dist[1];
// 		t1 = t[1];
// 		if (t[0] < t[1])
// 			dist = cy->dist[0];
// 		if (t[0] < t[1])
// 			t1 = t[0];
// 	}
// 	else if (cy->dist[0] >= 0 && cy->dist[0] <= cy->height && t[0] > EPSILON)
// 	{
// 		dist = cy->dist[0];
// 		t1 = t[0];
// 	}
// 	else
// 	{
// 		dist = cy->dist[1];
// 		t1 = t[1];
// 	}
// 	t[0] = t1;
// 	return (dist);
// }