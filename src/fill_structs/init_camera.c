/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:08:11 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/06 21:24:59 by vhovhann         ###   ########.fr       */
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
	if (!tmp)
		return (NULL);
	pos = ft_split(line[1], ',');
	dir = ft_split(line[2], ',');
	tmp->dir.x = ft_atof(dir[0]);
	tmp->dir.y = ft_atof(dir[1]);
	tmp->dir.z = ft_atof(dir[2]);
	tmp->pos.x = ft_atof(pos[0]);
	tmp->pos.y = ft_atof(pos[1]);
	tmp->pos.z = ft_atof(pos[2]);
	tmp->fov = ft_atof(line[3]);
	free_of_n(NULL, dir, pos, 2);
	return (tmp);
}
