/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:55:28 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/30 21:42:14 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_scene(t_scene **scene)
{
	if ((*scene)->amb)
	{
		if ((*scene)->amb->color)
			free((*scene)->amb->color);
		free((*scene)->amb);
	}
	if ((*scene)->light)
	{
		if ((*scene)->light->coord)
			free((*scene)->light->coord);
		if ((*scene)->light->color)
			free((*scene)->light->color);
		free((*scene)->light);
	}
	if ((*scene)->cam)
	{
		if ((*scene)->cam->dir)
			free((*scene)->cam->dir);
		if ((*scene)->cam->pos)
			free((*scene)->cam->pos);
		free((*scene)->cam);
	}
	if ((*scene)->data)
		free((*scene)->data);
	if ((*scene)->mlx)
		free((*scene)->mlx);
	if ((*scene)->pl)
		lstclear_pl(&(*scene)->pl);
	if ((*scene)->sph)
		lstclear_sp(&(*scene)->sph);
	if ((*scene)->cyl)
		lstclear_cyl(&(*scene)->cyl);
}
