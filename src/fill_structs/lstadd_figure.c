/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:13:32 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/19 15:13:10 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*lstadd_figure(char **line, int type);
t_figure	*lstadd_figure_2(t_figure *figure, char **line, int type);

t_figure	*lstadd_figure(char **line, int type)
{
	t_figure	*figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	if (!figure)
		return (NULL);
	figure->cyl = NULL;
	figure->sph = NULL;
	figure->pl = NULL;
	figure->cone = NULL;
	figure->next = NULL;
	figure->type = type;
	figure = lstadd_figure_2(figure, line, type);
	return (figure);
}

t_figure	*lstadd_figure_2(t_figure *figure, char **line, int type)
{
	if (type == CYLINDER)
	{
		figure->cyl = init_cyl(line);
		figure->spec = figure->cyl->spec;
		figure->color = figure->cyl->color;
	}
	else if (type == SPHERE)
	{
		figure->sph = init_sp(line);
		figure->spec = figure->sph->spec;
		figure->color = figure->sph->color;
	}
	else if (type == PLANE)
	{
		figure->pl = init_pl(line);
		figure->spec = figure->pl->spec;
		figure->color = figure->pl->color;
	}
	else if (type == CONE)
	{
		figure->cone = init_cone(line);
		figure->spec = figure->cone->spec;
		figure->color = figure->cone->color;
	}
	return (figure);
}
