/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:31 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/11 17:51:33 by rmkrtchy         ###   ########.fr       */
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
	r = substraction_vect(r, light);
	r_dot_v = dot_product_vect(r, v);
	if (r_dot_v > 0)
		i += scene->light->bright * \
			pow(r_dot_v / (length_vect(r) * length_vect(v)), fig->spec);
	return (i);
}

void	ray_norm(t_figure *fig, t_vect p)
{
	if (fig->type == SPHERE)
		fig->ray_norm = norm_vect(substraction_vect(p, fig->sph->coord));
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
	light = substraction_vect(scene->light->coord, p);
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

int	get_color(int red, int green, int blue, float bright)
{
	int	r;
	int	g;
	int	b;

	r = red * bright;
	g = green * bright;
	b = blue * bright;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}

int	pixel_col(t_scene *scene, t_vplane *v_plane, float x_angle, float y_angle)
{
	t_figure	*tmp1;
	float		min_t;
	int			color;

	tmp1 = scene->figure;
	min_t = INFINITY;
	scene->ray = new_vect(x_angle * v_plane->x_pixel, \
					y_angle * v_plane->y_pixel, -1);
	norm_vect(scene->ray);
	min_t = closest_inter(scene->cam->pos, scene->ray, scene->figure, &tmp1);
	if (min_t != INFINITY)
		color = get_color(tmp1->color->r, tmp1->color->g, \
				tmp1->color->b, compute_light(min_t, scene, tmp1));
	else
		color = get_color(0, 0, 0, 1);
	return (color);
}

void	ray_tracing(t_scene *scene, int mlx_x, int mlx_y)
{
	float		x_angle;
	float		y_angle;
	t_vplane	*v_plane;

	v_plane = get_vplane(scene->width, scene->height, scene->cam->fov);
	y_angle = (scene->height / 2) + 1;
	while (--y_angle >= scene->height / 2 * (-1))
	{
		mlx_x = 0;
		x_angle = ((scene->width / 2) * (-1)) - 1;
		while (++x_angle <= scene->width / 2)
		{
			my_mlx_pixel_put(scene->data, mlx_x, mlx_y, \
					pixel_col(scene, v_plane, x_angle, y_angle));
			mlx_x++;
		}
		mlx_y++;
	}
	free(v_plane);
}

t_vplane	*get_vplane(float width, float height, float fov)
{
	t_vplane	*v_plane;

	v_plane = malloc(sizeof(t_vplane));
	v_plane->width = 2 * tan((fov / 2) * (M_PI / 180));
	v_plane->height = v_plane->width / (width / height);
	v_plane->x_pixel = v_plane->width / width;
	v_plane->y_pixel = v_plane->height / height;
	return (v_plane);
}
