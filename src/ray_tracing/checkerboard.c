/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:48 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:08 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	uv_checkers(float height, float width)
{
	t_pattern	patt;

	patt.height = height;
	patt.width = width;
	patt.col1.b = 255;
	patt.col1.g = 255;
	patt.col1.r = 255;
	patt.col2.b = 0;
	patt.col2.g = 0;
	patt.col2.r = 0;
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

t_uv	get_uv(t_vect p, t_figure *fig)
{
	t_uv	uv;

	if (fig->pl->n_coord.x != 0.0001)
	{
		uv.u = p.z;
		uv.v = p.y;
	}
	else if (fig->pl->n_coord.y != 0.0001)
	{
		uv.u = p.x;
		uv.v = p.z;
	}
	else if (fig->pl->n_coord.z != 0.0001)
	{
		uv.u = p.x;
		uv.v = p.y;
	}
	else
	{
		uv.u = 0.0;
		uv.v = 0.0;
	}
	return (uv);
}

void	checkerboard(t_scene *scene, float t, t_figure *fig)
{
	float	theta;
	float	phi;
	t_vect	p;
	float	raw_u;
	t_uv	uv;

	p = norm_vect(sum_vect(scene->cam->pos, num_product_vect(scene->ray, t)));
	if (fig->type == SPHERE)
	{
		theta = atan2f(p.x, p.z);
		phi = acosf(p.y / fig->sph->radius);
		raw_u = theta / (2 * M_PI);
		uv.u = 1 - (raw_u + 0.5);
		uv.v = (1 - phi) / M_PI;
		fig->color = (uv_pattern_at (uv_checkers(300, 150), uv.u, uv.v));
	}
	if (fig->type == PLANE)
	{
		uv = get_uv(p, fig);
		fig->color = (uv_pattern_at (uv_checkers(100, 100), uv.u, uv.v));
	}
}
