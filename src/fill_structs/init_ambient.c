/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:13 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/15 14:47:50 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amb	*fill_amb(char **line);

t_amb	*fill_amb(char **line)
{
	t_amb	*tmp;
	char	**colors;

	tmp = (t_amb *)malloc(sizeof(t_amb));
	if (!tmp)
		return (NULL);
	colors = ft_split(line[2], ',');
	tmp->color.r = ft_atoi(colors[0]);
	tmp->color.g = ft_atoi(colors[1]);
	tmp->color.b = ft_atoi(colors[2]);
	tmp->ratio = ft_atof(line[1]);
	free_2d(colors);
	return (tmp);
}
