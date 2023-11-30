/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:45:20 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/30 21:34:25 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	compute_spec(t_scene *scene, t_vect light, float n_dot_l, t_figure *fig)
{
	t_vect	v;
	t_vect	r;
	float	i;
	float	r_dot_v;

	i = 0.0;
	v = num_product_vect(scene->ray, -1);
	r = num_product_vect(num_product_vect(fig->ray_norm, 2), n_dot_l);
	r = substract_v(r, light);
	r_dot_v = dot_product_vect(r, v);
	if (r_dot_v > 0)
		i += scene->light->bright * \
			powf(r_dot_v / (length_vect(r) * length_vect(v)), fig->spec);
	return (i);
}

float	compute_light(float dot, t_scene *scene, t_figure *tmp)
{
	t_vect		p;
	t_vect		light;
	t_figure	*shadow;
	float		n_dot_l;
	float		i;

	i = scene->amb->ratio;
	p = sum_vect(scene->cam->pos, num_product_vect(scene->ray, dot));
	ray_norm(tmp, p);
	light = substract_v(scene->light->coord, p);
	n_dot_l = dot_product_vect(tmp->ray_norm, light);
	shadow = NULL;
	if (closest_inter(p, light, scene->figure, &shadow) != INFINITY)
		return (i);
	if (n_dot_l > 0)
		i += scene->light->bright * n_dot_l / \
			(length_vect(tmp->ray_norm) * length_vect(light));
	if (tmp->spec > 0)
		i += compute_spec(scene, light, n_dot_l, tmp);
	return (i);
}
