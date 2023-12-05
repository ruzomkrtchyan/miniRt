/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:04:03 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/02 14:58:47 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	cylray_norm(t_math *math, t_vect ray, t_vect pos, t_cyl *cyl)
{
	float	dist;

	dist = closest_dist(cyl, math);
	return (norm_vect(substract_v(substract_v(num_product_vect(ray, math->x1), \
			num_product_vect(cyl->n_coord, dist)), \
			substract_v(cyl->cent, pos))));
}

float	closest_dist(t_cyl *cyl, t_math *m)
{
	float	dist;

	if (cyl->dist[0] >= 0 && cyl->dist[0] <= cyl->height && m->x1 > 0.001 && \
		cyl->dist[1] >= 0 && cyl->dist[1] <= cyl->height && m->x2 > 0.001)
	{
		if (m->x1 < m->x2)
		{
			dist = cyl->dist[0];
			return (dist);
		}
		dist = cyl->dist[1];
		m->x1 = m->x2;
		return (dist);
	}
	else if (cyl->dist[0] >= 0 && cyl->dist[0] <= cyl->height && m->x1 > 0.001)
	{
		dist = cyl->dist[0];
		return (dist);
	}
	else
	{
		dist = cyl->dist[1];
		m->x1 = m->x2;
		return (dist);
	}
}
