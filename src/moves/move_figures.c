/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:38:41 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/12 19:52:58 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_right(t_scene *scene);
void	move_left(t_scene *scene);

void	move_left(t_scene *scene)
{
	t_figure	*tmp;

	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sph->coord.x += 2;
		else if (tmp->type == CYLINDER)
			tmp->cyl->cent.x += 2;
		else if (tmp->type == PLANE)
			tmp->pl->coord.x += 2;
		tmp = tmp->next;
	}
	scene->light->coord.x += 2;
}

void	move_right(t_scene *scene)
{
	t_figure	*tmp;

	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sph->coord.x -= 2;
		else if (tmp->type == CYLINDER)
			tmp->cyl->cent.x -= 2;
		else if (tmp->type == PLANE)
			tmp->pl->coord.x -= 2;
		tmp = tmp->next;
	}
	scene->light->coord.x -= 2;
}
