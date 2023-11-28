/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:31 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/28 12:56:39 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_norm(t_figure *fig, t_vect p)
{
	if (fig->type == SPHERE)
		fig->ray_norm = norm_vect(substraction_vect(p, fig->sph->coord));
	else if (fig->type == PLANE)
		fig->ray_norm = fig->pl->n_coord;
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

	y_angle = (scene->height / 2) + 1;
	while (--y_angle >= scene->height / 2 * (-1))
	{
		mlx_x = 0;
		x_angle = ((scene->width / 2) * (-1)) - 1;
		while (++x_angle <= scene->width / 2)
		{
			my_mlx_pixel_put(scene->data, mlx_x, mlx_y, \
					pixel_col(scene, scene->v_plane, x_angle, y_angle));
			mlx_x++;
		}
		mlx_y++;
	}
}
