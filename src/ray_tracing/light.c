/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:45:20 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/17 16:33:20 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	compute_spec(t_scene *sc, t_vect light, t_figure *fig, t_light *lights)
{
	t_vect	v;
	t_vect	r;
	float	spec;
	float	r_dot_v;
	t_rgb	res;

	v = num_product_vect(sc->ray, -1);
	r = num_product_vect(num_product_vect(fig->ray_norm, 2), lights->n_dot_l);
	r = substract_v(r, light);
	r_dot_v = dot_product_vect(r, v);
	spec = lights->bright * \
			powf(r_dot_v / (length_vect(r) * length_vect(v)), fig->spec);
	res = n_prod_col(lights->color, spec);
	return (res);
}

int	compute_shadow(float dot, t_scene *scene, t_figure *tmp, t_light *lights)
{
	t_vect		p;
	t_vect		light;
	t_figure	*shadow;

	p = sum_vect(scene->cam->pos, num_product_vect(scene->ray, dot));
	ray_norm(tmp, p);
	light = substract_v(lights->coord, p);
	shadow = NULL;
	if (closest_inter(p, light, scene->figure, &shadow) != INFINITY)
		return (0);
	return (1);
}

t_rgb	compute_light(t_rgb fig_col, t_light *light, float n_dot_l)
{
	t_rgb	diff;

	diff = prod_col(fig_col, light->color, n_dot_l * light->bright);
	return (diff);
}
