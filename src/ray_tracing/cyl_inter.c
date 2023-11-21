/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:03:52 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/20 14:23:38 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	cyl_inter(t_vect pos, t_vect ray, t_cyl *cyl)
{
	t_math	math;
	float	proj[2];
	t_vect	p1;
	t_vect	p2;
	t_vect	x;
	
	x = substraction_vect(pos, cyl->coord);
	math.a = dot_product_vect(ray, ray) - powf(dot_product_vect(ray, cyl->n_coord), 2);
	math.b = 2 * (dot_product_vect(ray, x) - (dot_product_vect(ray, cyl->n_coord) * dot_product_vect(x, cyl->n_coord)));
	math.c = dot_product_vect(x, x) - powf(dot_product_vect(x, cyl->n_coord), 2) - powf(cyl->radius, 2);
	math.disc = math.b * math.b - (4 * math.a * math.c);
	if (math.disc > 0)
	{
		math.x1 = (-math.b - sqrt(math.disc)) / (2 * math.a);
		math.x2 = (-math.b + sqrt(math.disc)) / (2 * math.a);
		return (math.x1);
	}
	else
		return (0.0);
	p1 = sum_vect(pos, num_product_vect(ray, math.x1));
	p2 = sum_vect(pos, num_product_vect(ray, math.x2));
	proj[0] = dot_product_vect(substraction_vect(p1, cyl->coord), cyl->n_coord);
	if (proj[0] > 0 || proj[0] > dot_product_vect(cyl->n_coord, cyl->n_coord))
		return (math.x1);
	proj[1] = dot_product_vect(substraction_vect(p2, cyl->coord), cyl->n_coord);
	if (proj[1] > 0 || proj[1] > dot_product_vect(cyl->n_coord, cyl->n_coord))
		return (math.x2);
	return (0.0);
}
