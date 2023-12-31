/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:16:14 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/30 21:34:25 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	new_vect(float x, float y, float z)
{
	t_vect	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 1;
	return (new);
}

t_vect	substract_v(t_vect v1, t_vect v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vect	sum_vect(t_vect v1, t_vect v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vect	num_product_vect(t_vect vec, float num)
{
	vec.x *= num;
	vec.y *= num;
	vec.z *= num;
	return (vec);
}

float	length_vect(t_vect vec)
{
	float	length;

	length = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (length);
}
