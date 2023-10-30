/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:26:38 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/30 19:38:13 by rmkrtchy         ###   ########.fr       */
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
		// destroy_scene(&scene);
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
	(void)scene;
	// destroy_scene(&scene);
	exit (1);
}

int	mouse(void)
{
	printf("OK\n");
	return (1);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_create(t_scene *scene)
{
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->mlx->mlx = mlx_init();
	scene->mlx->mlx_win = mlx_new_window(scene->mlx->mlx, 1080, 720, "MiniRt");
	scene->mlx->img = mlx_new_image(scene->mlx->mlx, 1920, 1080);
	scene->mlx->addr = mlx_get_data_addr(scene->mlx->img, \
								&scene->mlx->bits_per_pixel, \
								&scene->mlx->line_length, &scene->mlx->endian);
	// my_mlx_pixel_put(scene->mlx, 5, 5, 0x00FF0000);
	ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
								scene->mlx->img, 0, 0);
	mlx_hook(scene->mlx->mlx_win, 2, 0, &mlx_keypress, scene);
	mlx_hook(scene->mlx->mlx_win, 4, 0, &button_press, scene);
	mlx_hook(scene->mlx->mlx_win, 6, 0, &mouse, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 0, &close_window, scene);
	mlx_loop(scene->mlx->mlx);
}
