/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:30:31 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/09 22:27:11 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			lstsize_figure(t_figure *lst);
t_figure	*lstlast_figure(t_figure *lst);
void		lstclear_figure(t_figure **lst);
void		lstback_figure(t_figure **pars, t_figure *new);
t_figure	*lstadd_figure(char **line, int type);

t_figure	*lstadd_figure(char **line, int type)
{
	t_figure	*figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	if (!figure)
		return (NULL);
	figure->cyl = NULL;
	figure->sph = NULL;
	figure->pl = NULL;
	figure->type = type;
	if (type == CYLINDER)
		figure->cyl = init_cyl(line);
	else if (type == SPHERE)
		figure->sph = init_sp(line);
	else if (type == PLANE)
		figure->pl = init_pl(line);
	figure->next = NULL;
	return (figure);
}

void	lstback_figure(t_figure **pars, t_figure *new)
{
	t_figure	*tmp;

	tmp = lstlast_figure(*pars);
	if (!tmp)
		*pars = new;
	else
		tmp->next = new;
}

void	lstclear_figure(t_figure **lst)
{
	t_figure	*ptr;

	ptr = NULL;
	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		if ((*lst)->type == CYLINDER)
		{
			free((*lst)->cyl->color);
			free((*lst)->cyl);
		}
		if ((*lst)->type == SPHERE)
		{
			free((*lst)->sph->color);
			free((*lst)->sph);
		}
		if ((*lst)->type == PLANE)
		{
			free((*lst)->pl->color);
			free((*lst)->pl);
		}
		free (*lst);
		(*lst) = ptr;
	}
	ptr = NULL;
}

t_figure	*lstlast_figure(t_figure *lst)
{
	t_figure	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	lstsize_figure(t_figure *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		(lst) = (lst)->next;
	}
	return (i);
}
