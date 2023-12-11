/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:09:16 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/11 18:45:13 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_scene_up(t_scene *scene);
void	rotate_scene_left(t_scene *scene);
void	rotate_scene_right(t_scene *scene);
void	rotate_scene_down(t_scene *scene);

void	rotate_scene_up(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_x(-scene->x_angle);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sph, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->pl, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cyl, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}

void	rotate_scene_down(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_x(scene->x_angle);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sph, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->pl, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cyl, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}

void	rotate_scene_left(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_y(scene->y_angle);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sph, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->pl, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cyl, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}

void	rotate_scene_right(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_y(-scene->y_angle);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sph, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->pl, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cyl, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}
