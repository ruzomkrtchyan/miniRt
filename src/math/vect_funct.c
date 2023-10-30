/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:16:14 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/30 19:01:56 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	*new_vect(float x, float y, float z)
{
	t_vect	*vector;

	vector = (t_vect *)malloc(sizeof(t_vect));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vect	*substraction_vect(t_vect *v1, t_vect *v2)
{
	t_vect	*res;

	res = new_vect(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (res);
}

float	length_vect(t_vect *vec)
{
	float	length;

	length = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (length);
}

float	dot_product_vect(t_vect *v1, t_vect *v2)
{
	float	res;

	res = ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
	return (res);
}

void	norm_vect(t_vect *vector)
{
	float	length;

	length = length_vect(vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
}
