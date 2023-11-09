/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:12:32 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/09 11:12:56 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dot_product_vect(t_vect v1, t_vect v2)
{
	float	res;

	res = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return (res);
}

void	norm_vect(t_vect vector)
{
	float	length;

	length = length_vect(vector);
	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
}
