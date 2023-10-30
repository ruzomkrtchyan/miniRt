/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:10 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/30 21:33:48 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	lstback_cyl(t_cyl **pars, t_cyl *new);
void	lstclear_cyl(t_cyl **lst);
int		lstsize_cyl(t_cyl *lst);
t_cyl	*lstlast_cyl(t_cyl *lst);
t_cyl	*lstadd_cyl(char **line);
t_cyl	*lstadd_cyl_2(t_cyl *tmp, char **vect, char **n_vect, char **colors);

t_cyl	*lstadd_cyl(char **line)
{
	t_cyl	*tmp;
	char	**colors;
	char	**vect;
	char	**n_vect;

	tmp = (t_cyl *)malloc(sizeof(t_cyl));
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	tmp->coord = (t_vect *)malloc(sizeof(t_vect));
	tmp->n_coord = (t_vect *)malloc(sizeof(t_vect));
	if (!tmp || !tmp->color || !tmp->coord || !tmp->n_coord)
		return (NULL);
	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	tmp->diam = ft_atof(line[3]);
	tmp->height = ft_atof(line[4]);
	colors = ft_split(line[5], ',');
	tmp = lstadd_cyl_2(tmp, vect, n_vect, colors);
	tmp->next = NULL;
	free_of_n(NULL, n_vect, colors, 3);
	free_2d(vect);
	return (tmp);
}

t_cyl	*lstadd_cyl_2(t_cyl *tmp, char **vect, char **n_vect, char **colors)
{
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->coord->x = ft_atof(vect[0]);
	tmp->coord->y = ft_atof(vect[1]);
	tmp->coord->z = ft_atof(vect[2]);
	tmp->n_coord->x = ft_atof(n_vect[0]);
	tmp->n_coord->y = ft_atof(n_vect[1]);
	tmp->n_coord->z = ft_atof(n_vect[2]);
	return (tmp);
}

void	lstback_cyl(t_cyl **pars, t_cyl *new)
{
	t_cyl	*tmp;

	tmp = lstlast_cyl(*pars);
	if (!tmp)
		*pars = new;
	else
		tmp->next = new;
}

t_cyl	*lstlast_cyl(t_cyl *lst)
{
	t_cyl	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	lstclear_cyl(t_cyl **lst)
{
	t_cyl	*ptr;

	ptr = NULL;
	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		free((*lst)->coord);
		free((*lst)->n_coord);
		free((*lst)->color);
		free (*lst);
		(*lst) = ptr;
	}
	ptr = NULL;
}
