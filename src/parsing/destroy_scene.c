/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:55:28 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:03 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_scene(t_scene **scene)
{
	if ((*scene)->amb)
		free((*scene)->amb);
	if ((*scene)->light)
		free((*scene)->light);
	if ((*scene)->cam)
		free((*scene)->cam);
	if ((*scene)->data)
		free((*scene)->data);
	if ((*scene)->mlx)
		free((*scene)->mlx);
	if ((*scene)->figure)
		lstclear_figure(&(*scene)->figure);
}
