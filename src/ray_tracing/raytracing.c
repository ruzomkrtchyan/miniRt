/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:31 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/30 20:07:02 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersection(t_cam *cam, t_vect *ray, t_sph *sph)
{
	float	b;
	float	c;
	float	disc;
	float	x1;
	float	x2;
	t_vect	*cam_to_sphere;

	x1 = 0;
	x2 = 0;
	cam_to_sphere = substraction_vect(cam->pos, sph->coord);
	b = 2 * (dot_product_vect(cam_to_sphere, ray));
	c = dot_product_vect(cam_to_sphere,cam_to_sphere) - (sph->radius * sph->radius);
	disc = (b * b) - (4 * c);
	free(cam_to_sphere);
	if (disc < 0)
		return (0);
	x1 = ((b * (-1)) - sqrt(disc)) / 2;
	x2 = ((b * (-1)) + sqrt(disc)) / 2;
	if (x1 > 0)
		return (1);
	return (0);
}

void	ray_tracing(t_scene *scene)
{
	float		x_angle;
	float		y_angle;
	float		x_ray;
	float		y_ray;
	int			color;
	int			mlx_x;
	int			mlx_y;
	t_vplane	*v_plane;
	t_vect		*ray;

	y_angle = (scene->height / 2);
	v_plane = get_vplane(scene->width, scene->height);
	mlx_y = 0;
	while (y_angle >= scene->height / 2 * (-1))
	{
		mlx_x = 0;
		y_ray = y_angle * v_plane->y_pixel;
		x_angle = ((scene->width / 2) * (-1));
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * v_plane->x_pixel;
			ray = new_vect(x_ray, y_ray, -1);
			norm_vect(ray);
			if (sphere_intersection(scene->cam, ray, scene->sph))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(scene->mlx, scene->mlx->mlx_win, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		mlx_y++;
		y_angle--;
	}
}

t_vplane	*get_vplane(float height, float width)
{
	t_vplane	*v_plane;

	v_plane = malloc(sizeof(t_vplane));
	v_plane->width = 1;
	v_plane->height = 1 / (width / height);
	v_plane->x_pixel = v_plane->width / width;
	v_plane->y_pixel = v_plane->height / height;
	return (v_plane);
}
