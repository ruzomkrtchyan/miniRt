/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:26:38 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/08 12:04:48 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_keypress(int keypress, t_scene *scene)
{
	(void)scene;
	if (keypress == W || keypress == UP)
		printf("GO TO UP\n");
	if (keypress == S || keypress == DOWN)
		printf("GO TO DOWN\n");
	if (keypress == A || keypress == LEFT)
		printf("GO TO LEFT\n");
	if (keypress == D || keypress == RIGHT)
		printf("GO TO RIGHT\n");
	if (keypress == ESC)
	{
		destroy_scene(&scene);
		system("leaks minirt");
		exit (1);
	}
	return (0);
}

int	button_press(void)
{
	printf("MOUSE HERE\n");
	return (1);
}

int	close_window(t_scene *scene)
{
	destroy_scene(&scene);
	exit (1);
}

int	mouse(void)
{
	printf("OK\n");
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	mlx_create(t_scene *scene)
{
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->data = (t_data *)malloc(sizeof(t_data));
	scene->data->width = scene->width;
	scene->data->height = scene->height;
	scene->mlx->mlx = mlx_init();
	scene->mlx->mlx_win = mlx_new_window(scene->mlx->mlx, 1080, 720, "MiniRt");
	scene->data->img = mlx_new_image(scene->mlx->mlx, 1080, 720);
	scene->data->addr = mlx_get_data_addr(scene->data->img, \
								&scene->data->bits_per_pixel, \
								&scene->data->line_length, &scene->data->endian);
	ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
								scene->data->img, 0, 0);
	mlx_hook(scene->mlx->mlx_win, 2, 0, &mlx_keypress, scene);
	// mlx_hook(scene->mlx->mlx_win, 4, 0, &button_press, scene);
	// mlx_hook(scene->mlx->mlx_win, 6, 0, &mouse, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 0, &close_window, scene);
	mlx_loop(scene->mlx->mlx);
}
