/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:26:38 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/11 10:41:07 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_create(t_scene *scene)
{
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->data = (t_data *)malloc(sizeof(t_data));
	scene->data->width = WIDTH;
	scene->data->height = HEIGHT;
	scene->mlx->mlx = mlx_init();
	scene->mlx->mlx_win = mlx_new_window(scene->mlx->mlx, WIDTH, HEIGHT, \
																"MiniRt");
	scene->data->img = mlx_new_image(scene->mlx->mlx, WIDTH, HEIGHT);
	scene->data->addr = mlx_get_data_addr(scene->data->img, \
							&scene->data->bits_per_pixel, \
							&scene->data->line_length, &scene->data->endian);
	// ray_tracing(scene, 0, 0);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
								scene->data->img, 0, 0);
	mlx_hook(scene->mlx->mlx_win, 2, 0, &mlx_keypress, scene);
	// mlx_hook(scene->mlx->mlx_win, 4, 0, &button_press, scene);
	// mlx_hook(scene->mlx->mlx_win, 6, 0, &mouse, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 0, &close_window, scene);
	mlx_loop(scene->mlx->mlx);
}
