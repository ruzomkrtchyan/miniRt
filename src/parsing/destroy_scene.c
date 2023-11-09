/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:55:28 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/09 22:28:13 by vhovhann         ###   ########.fr       */
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
		if ((*scene)->light->color)
			free((*scene)->light->color);
		free((*scene)->light);
	}
	if ((*scene)->cam)
		free((*scene)->cam);
	if ((*scene)->data)
		free((*scene)->data);
	if ((*scene)->mlx)
		free((*scene)->mlx);
	if ((*scene)->figure)
		lstclear_figure(&(*scene)->figure);
}
