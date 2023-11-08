/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:31 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/08 12:37:25 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	compute_light(float dot, t_scene *scene, t_vect ray, t_sph *tmp)
{
	t_vect	prod;
	t_vect	p;
	t_vect	norm;
	t_vect	light;
	t_vect	v;
	t_vect	r;
	float	n_dot_l;
	float	r_dot_v;
	float	i;

	prod = num_product_vect(ray, dot);
	p = sum_vect(scene->cam->pos, prod);
	norm = substraction_vect(p, tmp->coord);
	norm_vect(norm);
	light = substraction_vect(scene->light->coord, p);
	i = scene->amb->ratio;
	n_dot_l = dot_product_vect(norm, light);
	if (n_dot_l > 0)
		i += scene->light->bright * n_dot_l / (length_vect(norm) * length_vect(light));
	if (tmp->spec > 0)
	{
		v = num_product_vect(ray, -1);
		r = num_product_vect(num_product_vect(norm, 2), n_dot_l);
		r = substraction_vect(r, light);
		r_dot_v = dot_product_vect(r, v);
		if (r_dot_v > 0)
			i += scene->light->bright * pow(r_dot_v/(length_vect(r)*length_vect(v)), tmp->spec);
	}
	return(i);
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

float	sphere_intersection(t_cam *cam, t_vect ray, t_sph *sph)
{
	float	b;
	float	c;
	float	disc;
	float	x1;
	float	a;
	t_vect	cam_to_sphere;

	x1 = 0;
	cam_to_sphere = substraction_vect(cam->pos, sph->coord);
	b = 2 * (dot_product_vect(cam_to_sphere, ray));
	c = dot_product_vect(cam_to_sphere,cam_to_sphere) - (sph->radius * sph->radius);
	a = dot_product_vect(ray, ray);
	disc = (b * b) - (4 * a * c);
	if (disc < 0)
		return (0);
	x1 = ((-b) - sqrt(disc)) / (2 * a);
	if (x1 > 0)
		return (x1);
	return (0);
}

void	ray_tracing(t_scene *scene)
{
	float		x_angle;
	float		y_angle;
	float		x_ray;
	float		y_ray;
	float		dot;
	float		min_t;
	int			color;
	int			mlx_x;
	int			mlx_y;
	t_vplane	*v_plane;
	t_vect		ray;
	t_sph		*tmp;
	t_sph		*tmp1;

	v_plane = get_vplane(scene->width, scene->height, scene->cam->fov);
	y_angle = (scene->height / 2);
	mlx_y = 0;
	tmp = scene->sph;
	while (y_angle >= scene->height / 2 * (-1))
	{
		mlx_x = 0;
		y_ray = y_angle * v_plane->y_pixel;
		x_angle = ((scene->width / 2) * (-1));
		while (x_angle <= scene->width / 2)
		{
			min_t = INFINITY;
			dot = INFINITY;
			x_ray = x_angle * v_plane->x_pixel;
			ray = new_vect(x_ray, y_ray, -1);
			norm_vect(ray);
			while (tmp)
			{
				dot = sphere_intersection(scene->cam, ray, tmp);
				if (dot && dot < min_t)
				{
					min_t = dot;
					tmp1 = tmp;
				}
				tmp = tmp->next;
			}
			if (min_t != INFINITY)
				color = get_color(tmp1->color->r, tmp1->color->g, \
						tmp1->color->b, compute_light(min_t, scene, ray, tmp1));
			else
				color = get_color(0, 0, 0, 1);
			my_mlx_pixel_put(scene->data, mlx_x, mlx_y, color);
			x_angle++;
			mlx_x++;
			tmp = scene->sph;
		}
		mlx_y++;
		y_angle--;
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
