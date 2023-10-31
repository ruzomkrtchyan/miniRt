/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:00 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/31 13:43:23 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	lstback_sp(t_sph **pars, t_sph *new);
void	lstclear_sp(t_sph **lst);
int		lstsize_sp(t_sph *lst);
t_sph	*lstadd_sp(char **line);
t_sph	*lstlast_sp(t_sph *lst);

t_sph	*lstadd_sp(char **line)
{
	t_sph	*tmp;
	char	**colors;
	char	**vect;

	tmp = (t_sph *)malloc(sizeof(t_sph));
	tmp->coord = (t_vect *)malloc(sizeof(t_vect));
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	if (!tmp || !tmp->coord || !tmp->color)
		return (NULL);
	vect = ft_split(line[1], ',');
	tmp->radius = ft_atof(line[2]) / 2;
	colors = ft_split(line[3], ',');
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->coord->x = ft_atof(vect[0]);
	tmp->coord->y = ft_atof(vect[1]);
	tmp->coord->z = ft_atof(vect[2]);
	tmp->next = NULL;
	tmp->prev = NULL;
	free_of_n(NULL, colors, vect, 2);
	return (tmp);
}

void	lstback_sp(t_sph **pars, t_sph *new)
{
	t_sph	*tmp;

	tmp = lstlast_sp(*pars);
	if (!tmp)
		*pars = new;
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}

void	lstclear_sp(t_sph **lst)
{
	t_sph	*ptr;

	ptr = NULL;
	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		free((*lst)->coord);
		free((*lst)->color);
		free (*lst);
		(*lst) = ptr;
	}
	ptr = NULL;
}

t_sph	*lstlast_sp(t_sph *lst)
{
	t_sph	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	lstsize_sp(t_sph *lst)
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
