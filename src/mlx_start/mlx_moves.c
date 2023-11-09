/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/09 11:14:09 by vhovhann         ###   ########.fr       */
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
		mlx_destroy_window(scene->mlx->mlx, scene->mlx->mlx_win);
		destroy_scene(&scene);
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
