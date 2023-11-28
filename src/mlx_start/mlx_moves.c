/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/28 18:12:13 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_keypress(int keypress, t_scene **scene)
{
	t_figure *tmp = (*scene)->figure;
	if (keypress == W || keypress == UP)
	{
		(*scene)->cam->pos.z -= 1;
		printf("GO TO UP\n");
	}
	if (keypress == S || keypress == DOWN)
	{
		(*scene)->cam->pos.z += 100;
		printf("GO TO DOWN\n");
	}
	if (keypress == A || keypress == LEFT)
	{
			while (tmp)
			{
				if (tmp->type == SPHERE)
					tmp->sph->coord.x -= 2;
				tmp = tmp->next;
			}
			printf("GO TO LEFT\n");
	}
	if (keypress == D || keypress == RIGHT)
	{ 
			while (tmp)
			{
				if (tmp->type == SPHERE)
					tmp->sph->coord.x += 2;
				tmp = tmp->next;
			}
			printf("GO TO RIGHT\n");
	}
	(*scene)->data->img = mlx_new_image((*scene)->mlx->mlx, WIDTH, HEIGHT);
	(*scene)->data->addr = mlx_get_data_addr((*scene)->data->img, \
			&(*scene)->data->bits_per_pixel, \
			&(*scene)->data->line_length, &(*scene)->data->endian);
	ray_tracing(*scene, 0, 0);
	mlx_put_image_to_window((*scene)->mlx->mlx, (*scene)->mlx->mlx_win, \
								(*scene)->data->img, 0, 0);
	if (keypress == ESC)
	{
		mlx_destroy_window((*scene)->mlx->mlx, (*scene)->mlx->mlx_win);
		destroy_scene(scene);
		exit (0);
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
	mlx_destroy_window(scene->mlx->mlx, scene->mlx->mlx_win);
	destroy_scene(&scene);
	exit (0);
}

int	mouse(void)
{
	printf("OK\n");
	return (1);
}
