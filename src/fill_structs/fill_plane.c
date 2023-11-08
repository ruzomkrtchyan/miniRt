/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:03 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/08 17:35:42 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	lstback_pl(t_pl **pars, t_pl *new);
void	lstclear_pl(t_pl **lst);
int		lstsize_pl(t_pl *lst);
t_pl	*lstadd_pl(char **line);
t_pl	*lstlast_pl(t_pl *lst);

t_pl	*lstadd_pl(char **line)
{
	t_pl	*tmp;
	char	**colors;
	char	**vect;
	char	**n_vect;

	tmp = (t_pl *)malloc(sizeof(t_pl));
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	if (!tmp || !tmp->color)
		return (NULL);
	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	colors = ft_split(line[3], ',');
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->coord.x = ft_atof(vect[0]);
	tmp->coord.y = ft_atof(vect[1]);
	tmp->coord.z = ft_atof(vect[2]);
	tmp->n_coord.x = ft_atof(n_vect[0]);
	tmp->n_coord.y = ft_atof(n_vect[1]);
	tmp->n_coord.z = ft_atof(n_vect[2]);
	tmp->next = NULL;
	free_of_n(NULL, n_vect, colors, 3);
	free_2d(vect);
	return (tmp);
}

void	lstback_pl(t_pl **pars, t_pl *new)
{
	t_pl	*tmp;

	tmp = lstlast_pl(*pars);
	if (!tmp)
		*pars = new;
	else
		tmp->next = new;
}

void	lstclear_pl(t_pl **lst)
{
	t_pl	*ptr;

	ptr = NULL;
	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		free((*lst)->color);
		free (*lst);
		(*lst) = ptr;
	}
	ptr = NULL;
}

t_pl	*lstlast_pl(t_pl *lst)
{
	t_pl	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	lstsize_pl(t_pl *lst)
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
