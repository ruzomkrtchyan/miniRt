/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:26:38 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/21 16:37:15 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_thread_struct(t_thread	thr[NUM_THREAD], t_scene *scene)
{
	int			i;

	i = NUM_THREAD - 1;
	while (i >= 0)
	{
		thr[i].height = HEIGHT / (NUM_THREAD - i);
		thr[i].width = WIDTH / (NUM_THREAD - i);
		thr[i].old_height = HEIGHT - (HEIGHT / (NUM_THREAD - i));
		thr[i].old_width = WIDTH - (WIDTH / (NUM_THREAD - i));
		if (scene->cam)
			thr[i].vplane = get_vplane(thr[i].width, thr[i].height, \
														scene->cam->fov);
		else
			thr[i].vplane = NULL;
		thr[i].scene = scene;
		i--;
	}
}

void	start_threads(t_thread thr[NUM_THREAD])
{
	pthread_t	t1[NUM_THREAD];
	int			i;

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
}

void	mlx_create(t_scene *scene)
{
	t_thread	thr[NUM_THREAD];

	fill_thread_struct(thr, scene);
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->data = (t_data *)malloc(sizeof(t_data));
	scene->mlx->mlx = mlx_init();
	scene->mlx->mlx_win = mlx_new_window(scene->mlx->mlx, WIDTH, HEIGHT, \
																"MiniRt");
	scene->data->img = mlx_new_image(scene->mlx->mlx, WIDTH, HEIGHT);
	scene->data->addr = mlx_get_data_addr(scene->data->img, \
							&scene->data->bits_per_pixel, \
							&scene->data->line_length, &scene->data->endian);
	if (scene->figure && scene->cam && scene->amb)
		start_threads(thr);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
								scene->data->img, 0, 0);
	mlx_hook(scene->mlx->mlx_win, 2, 0, &mlx_keypress, &thr);
	mlx_hook(scene->mlx->mlx_win, 17, 0, (t_hook_helper)close_window, &thr);
	mlx_loop(scene->mlx->mlx);
}
