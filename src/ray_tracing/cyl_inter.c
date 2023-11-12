/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:03:52 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/12 20:18:29 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	cyl_inter(t_vect pos, t_vect ray, t_cyl *cyl)
{
	t_math	math;
	t_vect	x;
	
	x = substraction_vect(pos, cyl->coord);
	math.a = dot_product_vect(ray, ray) - powf(dot_product_vect(ray, cyl->n_coord), 2);
	math.b = 2 * (dot_product_vect(ray, x) - (dot_product_vect(ray, cyl->n_coord) * dot_product_vect(x, cyl->n_coord)));
	math.c = dot_product_vect(x, x) - powf(dot_product_vect(x, cyl->n_coord), 2) - powf(cyl->radius, 2);
	math.disc = math.b * math.b - (4 * math.a * math.c);
}
