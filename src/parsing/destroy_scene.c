/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:55:28 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/08 12:33:53 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_scene_2(t_scene **scene);

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
		if ((*scene)->light->color)
			free((*scene)->light->color);
		free((*scene)->light);
	}
	if ((*scene)->cam)
		free((*scene)->cam);
	destroy_scene_2(scene);
}

void	destroy_scene_2(t_scene **scene)
{
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
