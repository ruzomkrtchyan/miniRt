/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:38:41 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/18 15:55:40 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_right(t_scene *scene);
void	move_left(t_scene *scene);

void	move_left(t_scene *scene)
{
	t_figure	*tmp;
	t_light		*l_tmp;

	tmp = scene->figure;
	l_tmp = scene->light;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sph->coord.x += 2;
		else if (tmp->type == CYLINDER)
			tmp->cyl->cent.x += 2;
		else if (tmp->type == PLANE)
			tmp->pl->coord.x += 2;
		else if (tmp->type == CONE)
			tmp->cone->coord.x += 2;
		tmp = tmp->next;
	}
	while (l_tmp)
	{
		l_tmp->coord.x += 2;
		l_tmp = l_tmp->next;
	}
}

void	move_right(t_scene *scene)
{
	t_figure	*tmp;
	t_light		*l_tmp;

	tmp = scene->figure;
	l_tmp = scene->light;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sph->coord.x -= 2;
		else if (tmp->type == CYLINDER)
			tmp->cyl->cent.x -= 2;
		else if (tmp->type == PLANE)
			tmp->pl->coord.x -= 2;
		else if (tmp->type == CONE)
			tmp->cone->coord.x -= 2;
		tmp = tmp->next;
	}
	while (l_tmp)
	{
		l_tmp->coord.x -= 2;
		l_tmp = l_tmp->next;
	}
}
