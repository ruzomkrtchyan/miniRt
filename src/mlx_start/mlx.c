/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:26:38 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/25 19:13:28 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_keypress(int keypress, t_scene *scene)
{
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
		exit (1);
	}
	return (0);
}

int	close_window(t_scene *scene)
{
	destroy_scene(&scene);
	exit (1);
}

void	mlx_create(t_scene *scene)
{
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->mlx->mlx = mlx_init();
	scene->mlx->mlx_win = mlx_new_window(scene->mlx->mlx, 1080, 720, "MiniRt");
	mlx_hook(scene->mlx->mlx_win, 2, 0, &mlx_keypress, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 0, &close_window, scene);
	mlx_loop(scene->mlx->mlx);
}