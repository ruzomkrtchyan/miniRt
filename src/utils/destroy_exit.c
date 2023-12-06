/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:52:55 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/06 19:03:21 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_exit(t_thread *thr)
{
	mlx_destroy_image(thr->scene->mlx->mlx, thr->scene->data->img);
	mlx_destroy_window(thr->scene->mlx->mlx, thr->scene->mlx->mlx_win);
	destroy_scene(&thr->scene);
	free(thr->vplane);
	exit (1);
}
