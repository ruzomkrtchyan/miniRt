/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:13:32 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/11 17:17:00 by vhovhann         ###   ########.fr       */
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
	figure->next = NULL;
	figure->type = type;
	figure->spec = 30.0;
	figure = lstadd_figure_2(figure, line, type);
	return (figure);
}

t_figure	*lstadd_figure_2(t_figure *figure, char **line, int type)
{
	if (type == CYLINDER)
	{
		figure->cyl = init_cyl(line);
		figure->color = figure->cyl->color;
	}
	else if (type == SPHERE)
	{
		figure->sph = init_sp(line);
		figure->color = figure->sph->color;
	}
	else if (type == PLANE)
	{
		figure->pl = init_pl(line);
		figure->color = figure->pl->color;
	}
	return (figure);
}
