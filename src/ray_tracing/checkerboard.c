/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:48 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/21 14:09:30 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	uv_checkers(float height, float width)
{
	t_pattern	patt;

	patt.height = height;
	patt.width = width;
	patt.col1.b = 255;
	patt.col1.g = 0;
	patt.col1.r = 20;
	patt.col2.b = 100;
	patt.col2.g = 0;
	patt.col2.r = 255;
	return (patt);
}

t_rgb	uv_pattern_at(t_pattern patt, float u, float v)
{
	float	u2;
	float	v2;

	u2 = floorf(u * patt.width);
	v2 = floorf(v * patt.height);
	if (fmodf(u2 + v2, 2) == 0)
		return (patt.col1);
	return (patt.col2);
}

void	checkerboard(t_scene *scene, float t, t_figure *fig)
{
	float	theta;
	float	phi;
	t_vect	p;
	float	raw_u;
	t_uv	uv;

	p = sum_vect(scene->cam->pos, num_product_vect(scene->ray, t));
	p = norm_vect(substract_v(p, fig->sph->coord));
	if (fig->type == SPHERE)
	{
		theta = atan2f(p.x, p.z);
		phi = acosf(p.y / fig->sph->radius);
		raw_u = theta / (2 * M_PI);
		uv.u = 1 - (raw_u + 0.5);
		uv.v = (1 - phi) / M_PI;
		fig->color = (uv_pattern_at (uv_checkers(15, 15), uv.u, uv.v));
	}
}
