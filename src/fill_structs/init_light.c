/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:09 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/06 21:32:37 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*lstadd_light(char **line);

t_light	*lstadd_light(char **line)
{
	t_light	*tmp;
	char	**colors;
	char	**vect;

	tmp = (t_light *)malloc(sizeof(t_light));
	tmp->color = (t_rgb *)malloc(sizeof(t_rgb));
	if (!tmp || !tmp->color)
		return (NULL);
	vect = ft_split(line[1], ',');
	tmp->bright = ft_atof(line[2]);
	colors = ft_split(line[3], ',');
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->coord.x = ft_atof(vect[0]);
	tmp->coord.y = ft_atof(vect[1]);
	tmp->coord.z = ft_atof(vect[2]);
	tmp->next = NULL;
	free_of_n(NULL, colors, vect, 2);
	return (tmp);
}

void	lstback_light(t_light **pars, t_light *new)
{
	t_light	*tmp;

	tmp = lstlast_light(*pars);
	if (!tmp)
		*pars = new;
	else
		tmp->next = new;
}

void	lstclear_light(t_light **lst)
{
	t_light	*ptr;

	ptr = NULL;
	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		free(*lst);
		(*lst) = ptr;
	}
	ptr = NULL;
}

t_light	*lstlast_light(t_light *lst)
{
	t_light	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	lstsize_light(t_light *lst)
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
