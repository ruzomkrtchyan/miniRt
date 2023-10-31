/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:11 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/31 13:14:17 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*fill_cam(char **line);

t_cam	*fill_cam(char **line)
{
	t_cam	*tmp;
	char	**dir;
	char	**pos;

	tmp = (t_cam *)malloc(sizeof(t_cam));
	tmp->dir = (t_vect *)malloc(sizeof(t_vect));
	tmp->pos = (t_vect *)malloc(sizeof(t_vect));
	if (!tmp || !tmp->pos || !tmp->dir)
		return (NULL);
	pos = ft_split(line[1], ',');
	dir = ft_split(line[2], ',');
	tmp->dir->x = ft_atof(dir[0]);
	tmp->dir->y = ft_atof(dir[1]);
	tmp->dir->z = ft_atof(dir[2]);
	tmp->pos->x = ft_atof(pos[0]);
	tmp->pos->y = ft_atof(pos[1]);
	tmp->pos->z = ft_atof(pos[2]);
	tmp->fov = ft_atof(line[3]);
	free_of_n(NULL, dir, pos, 2);
	return (tmp);
}
