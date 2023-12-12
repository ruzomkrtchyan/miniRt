/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_or_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:58:42 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/12 19:51:30 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	_move_(int keypress, t_scene *scene);
void	_rotate_(int keypress, t_scene *scene);

void	_rotate_(int keypress, t_scene *scene)
{
	if (keypress == W)
		rotate_scene_up(scene);
	else if (keypress == S)
		rotate_scene_down(scene);
	else if (keypress == D)
		rotate_scene_left(scene);
	else if (keypress == A)
		rotate_scene_right(scene);
}

void	_move_(int keypress, t_scene *scene)
{
	if (keypress == INCREASE)
		scene->cam->pos.z -= 5;
	else if (keypress == DECREASE)
		scene->cam->pos.z += 5;
	else if (keypress == LEFT)
		move_left(scene);
	else if (keypress == RIGHT)
		move_right(scene);
}
