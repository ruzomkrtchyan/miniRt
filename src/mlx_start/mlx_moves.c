/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/04 17:40:37 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_keypress(int keypress, t_thread *thr)
{
	int			i;
	pthread_t	t1[NUM_THREAD];
	t_figure	*tmp;

	tmp = thr->scene->figure;
	if (keypress == W || keypress == UP)
		thr->scene->cam->pos.z -= 1;
	if (keypress == S || keypress == DOWN)
		thr->scene->cam->pos.z += 100;
	if (keypress == A || keypress == LEFT)
	{
		while (tmp)
		{
			if (tmp->type == SPHERE)
				tmp->sph->coord.x -= 2;
			tmp = tmp->next;
		}
	}
	if (keypress == D || keypress == RIGHT)
	{
		while (tmp)
		{
			if (tmp->type == SPHERE)
				tmp->sph->coord.x += 2;
			tmp = tmp->next;
		}
	}
	if (keypress == ESC)
	{
		mlx_destroy_window(thr->scene->mlx->mlx, thr->scene->mlx->mlx_win);
		destroy_scene(&thr->scene);
		free(thr->vplane);
		exit (0);
	}
	thr->scene->data->img = mlx_new_image(thr->scene->mlx->mlx, WIDTH, HEIGHT);
	thr->scene->data->addr = mlx_get_data_addr(thr->scene->data->img, \
			&thr->scene->data->bits_per_pixel, \
			&thr->scene->data->line_length, &thr->scene->data->endian);
	i = -1;
	while (++i < NUM_THREAD)
	{
		if (pthread_create(&t1[i], NULL, ray_tracing, &thr[i]))
		{
			mlx_destroy_window(thr->scene->mlx->mlx, thr->scene->mlx->mlx_win);
			destroy_scene(&thr->scene);
			free(thr->vplane);
			exit(1);
		}
	}
	i = -1;
	while (++i < NUM_THREAD)
		pthread_join(t1[i], NULL);
	mlx_put_image_to_window(thr->scene->mlx->mlx, thr->scene->mlx->mlx_win, \
								thr->scene->data->img, 0, 0);
	return (0);
}

int	button_press(void)
{
	printf("MOUSE HERE\n");
	return (1);
}

int	close_window(t_scene *scene)
{
	mlx_destroy_window(scene->mlx->mlx, scene->mlx->mlx_win);
	destroy_scene(&scene);
	exit (0);
}

int	mouse(void)
{
	printf("OK\n");
	return (1);
}
