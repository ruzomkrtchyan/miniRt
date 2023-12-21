/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/21 16:36:53 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_keypress(int keypress, t_thread thr[NUM_THREAD])
{
	if (keypress == ESC)
		destroy_exit(thr);
	if (thr->scene->figure && thr->scene->cam && thr->scene->amb)
	{
		if (keypress == A || keypress == S || keypress == D || keypress == W)
			_rotate_(keypress, thr->scene);
		else if (keypress == LEFT || keypress == RIGHT || \
								keypress == DECREASE || keypress == INCREASE)
			_move_(keypress, thr->scene);
		if (keypress == ESC)
			destroy_exit(thr);
		mlx_destroy_image(thr->scene->mlx->mlx, thr->scene->data->img);
		thr->scene->data->img = mlx_new_image(thr->scene->mlx->mlx, WIDTH, \
																	HEIGHT);
		thr->scene->data->addr = mlx_get_data_addr(thr->scene->data->img, \
				&thr->scene->data->bits_per_pixel, \
				&thr->scene->data->line_length, &thr->scene->data->endian);
		start_threads(thr);
		mlx_put_image_to_window(thr->scene->mlx->mlx, thr->scene->mlx->mlx_win, \
									thr->scene->data->img, 0, 0);
	}
	return (0);
}

void	close_window(t_thread *thr)
{
	destroy_exit(thr);
}
