/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:30:31 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/11 17:17:50 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			lstsize_figure(t_figure *lst);
t_figure	*lstlast_figure(t_figure *lst);
void		lstclear_figure(t_figure **lst);
void		lstback_figure(t_figure **pars, t_figure *new);

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
		else if ((*lst)->type == SPHERE)
		{
			free((*lst)->sph->color);
			free((*lst)->sph);
		}
		else if ((*lst)->type == PLANE)
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
