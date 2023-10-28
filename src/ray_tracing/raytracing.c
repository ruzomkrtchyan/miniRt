/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:53:31 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/27 16:11:40 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_tracing(t_scene *scene)
{
	float		x_angle;
	float		y_angle;
	float		x_ray;
	float		y_ray;
	t_vplane	*vplane;
	t_vect		*ray;

	y_angle = (scene->height / 2) * (-1);
	vplane = get_vplane(scene->width, scene->height);
	while (y_angle >= scene->height / 2)
	{
		y_ray = y_angle * v_plane->y_pixel;
		x_angle = ((scene->width / 2) * (-1));
		while (x_angle >= scene->width / 2)
		{
			x_ray = r_angle * v_plane->x_pixel;
			ray = new_vect(x_ray, y_ray, -1);
			if()
			x_angle++;
		}
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
	v_plane->y_pixel = v_pane->height / height;
	return (v_plane);
}
