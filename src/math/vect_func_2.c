/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:12:32 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/28 15:09:36 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dist_vect(t_vect v1, t_vect v2)
{
	float	dist;

	dist = sqrt(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2) \
			+ powf(v1.z - v2.z, 2));
	return (dist);
}

float	dot_product_vect(t_vect v1, t_vect v2)
{
	float	res;

	res = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return (res);
}

t_vect	norm_vect(t_vect vector)
{
	float	length;

	length = length_vect(vector);
	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return (vector);
}
