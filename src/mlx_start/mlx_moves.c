/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/06 21:38:26 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_keypress(int keypress, t_thread thr[NUM_THREAD])
{
	// if (keypress == W)
	// 	thr->scene->cam->pos.z -= 10;
	// else if (keypress == S)
	// 	thr->scene->cam->pos.z += 50;
	if (keypress == UP)
		move_up(&thr->scene->figure);
	else if (keypress == DOWN)
		move_down(&thr->scene->figure);
	else if (keypress == LEFT)
		move_left(&thr->scene->figure);
	else if (keypress == RIGHT)
		move_right(&thr->scene->figure);
	else if (keypress == ESC)
		destroy_exit(thr);
	mlx_destroy_image(thr->scene->mlx->mlx, thr->scene->data->img);
	thr->scene->data->img = mlx_new_image(thr->scene->mlx->mlx, WIDTH, HEIGHT);
	thr->scene->data->addr = mlx_get_data_addr(thr->scene->data->img, \
			&thr->scene->data->bits_per_pixel, \
			&thr->scene->data->line_length, &thr->scene->data->endian);
	start_threads(thr);
	mlx_put_image_to_window(thr->scene->mlx->mlx, thr->scene->mlx->mlx_win, \
								thr->scene->data->img, 0, 0);
	return (0);
}

int	button_press(void)
{
	printf("MOUSE HERE\n");
	return (1);
}

void	close_window(t_thread *thr)
{
	destroy_exit(thr);
}

int	mouse(void)
{
	printf("OK\n");
	return (1);
}
