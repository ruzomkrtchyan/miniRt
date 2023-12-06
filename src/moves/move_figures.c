/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:38:41 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/06 17:44:48 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_right(t_figure **figure);
void	move_left(t_figure **figure);
void	move_down(t_figure **figure);
void	move_up(t_figure **figure);

void	move_up(t_figure **figure)
{
	t_figure	*tmp;

	tmp = (*figure);
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sph->coord.y -= 2;
		else if (tmp->type == CYLINDER)
			tmp->cyl->cent.y -= 2;
		else if (tmp->type == PLANE)
			tmp->pl->coord.y -= 2;
		tmp = tmp->next;
	}
}

void	move_down(t_figure **figure)
{
	t_figure	*tmp;

	tmp = (*figure);
	while (tmp)
	{
		if (tmp->type == SPHERE)
			tmp->sph->coord.y += 2;
		else if (tmp->type == CYLINDER)
			tmp->cyl->cent.y += 2;
		else if (tmp->type == PLANE)
			tmp->pl->coord.y += 2;
		tmp = tmp->next;
	}
}

void	move_left(t_figure **figure)
{
	t_figure	*tmp;

	tmp = (*figure);
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
}

void	move_right(t_figure **figure)
{
	t_figure	*tmp;

	tmp = (*figure);
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
}
