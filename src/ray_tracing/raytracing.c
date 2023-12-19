/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:31 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/19 14:16:10 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_norm(t_figure *fig, t_vect p, float t, t_scene *scene)
{
	if (fig->type == SPHERE)
		fig->ray_norm = norm_vect(substract_v(p, fig->sph->coord));
	else if (fig->type == PLANE)
		fig->ray_norm = fig->pl->n_coord;
	else if (fig->type == CYLINDER)
		fig->ray_norm = fig->cyl->ray_norm;
	else if (fig->type == CONE)
		fig->ray_norm = norm_cone(fig->cone, p, t, scene);
}

int	get_color(t_figure *fig, float min_t, t_scene *scene, t_rgb amb)
{
	t_light	*lights;
	t_rgb	col;
	t_vect	light;
	t_vect	p;

	lights = scene->light;
	col.r = 0;
	col.g = 0;
	col.b = 0;
	while (lights)
	{
		col = add_col(col, amb);
		if (compute_shadow(min_t, scene, fig, lights) != 0)
		{
			p = sum_vect(scene->cam->pos, num_product_vect(scene->ray, min_t));
			ray_norm(fig, p, min_t, scene);
			light = norm_vect(substract_v(lights->coord, p));
			lights->n_dot_l = dot_product_vect(fig->ray_norm, light);
			if (lights->n_dot_l > 0)
				col = add_col(add_col(col, compute_light(fig->color, lights, \
				lights->n_dot_l)), compute_spec(scene, light, fig, lights));
		}
		lights = lights->next;
	}
	return (col.r << 16 | col.g << 8 | col.b);
}

int	pixel_col(t_scene *scene, t_vplane *v_plane, float x_angle, float y_angle)
{
	t_figure	*tmp1;
	float		min_t;
	int			color;
	t_rgb		amb;

	tmp1 = scene->figure;
	min_t = INFINITY;
	scene->ray = new_vect(x_angle * v_plane->x_pixel, \
					y_angle * v_plane->y_pixel, -1);
	min_t = closest_inter(scene->cam->pos, scene->ray, scene->figure, &tmp1);
	amb = prod_col(tmp1->color, scene->amb->color, scene->amb->ratio);
	if (min_t != INFINITY)
		color = checkerboard(scene, min_t);
	else
		color = 0;
	return (color);
}

void	*ray_tracing(void *arg)
{
	t_thread	*thr;
	t_scene		*scene;

	thr = arg;
	scene = thr->scene;
	thr->y_angle = thr->height / 2 + 1;
	thr->mlx_y = thr->old_height;
	while (--(thr->y_angle) >= (thr->height / 2 * (-1)) && \
													thr->mlx_y <= thr->height)
	{
		thr->mlx_x = thr->old_width;
		thr->x_angle = ((thr->width / 2) * (-1)) - 1;
		while (++(thr->x_angle) <= thr->width / 2 && thr->mlx_x <= thr->width)
		{
			my_mlx_pixel_put(scene->data, thr->mlx_x, thr->mlx_y, \
				pixel_col(scene, thr->vplane, (thr->x_angle), (thr->y_angle)));
			(thr->mlx_x)++;
		}
		(thr->mlx_y)++;
	}
	pthread_exit(NULL);
}
