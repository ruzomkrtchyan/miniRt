/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:07:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/28 16:15:36 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*pars(char **arr, t_scene *scene);
int		check_ident_args(char **line);
void	fill_scene(char **line, t_scene *scene);

void	init_scene(t_scene **scene)
{
	(*scene)->amb = NULL;
	(*scene)->light = NULL;
	(*scene)->figure = NULL;
	(*scene)->cam = NULL;
	(*scene)->data = NULL;
	(*scene)->mlx = NULL;
	(*scene)->x_angle = 0.3;
	(*scene)->y_angle = 0.3;
	(*scene)->z_angle = 0.3;
	(*scene)->vplane = NULL;
	(*scene)->height = HEIGHT;
	(*scene)->width = WIDTH;
}

t_scene	*pars(char **arr, t_scene *scene)
{
	int			i;
	char		**line;

	line = NULL;
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] != '#')
		{
			line = ft_split(arr[i], ' ');
			if (check_identifier(line) || check_ident_args(line))
				exit(1 + free_of_n(NULL, line, arr, 2));
			free_2d(line);
		}
	}
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(&scene);
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] != '#')
		{
			line = ft_split(arr[i], ' ');
			fill_scene(line, scene);
			free_2d(line);
		}
	}
	scene->vplane = get_vplane(scene->width, scene->height, scene->cam->fov);
	return (scene);
}

int	check_ident_args(char **line)
{
	int	i;

	i = 0;
	if (!ft_strcmp(line[0], "A"))
		i = check_args_amb(line);
	else if (!ft_strcmp(line[0], "C"))
		i = check_args_cam(line);
	else if (!ft_strcmp(line[0], "L"))
		i = check_args_light(line);
	else if (!ft_strcmp(line[0], "pl"))
		i = check_args_plane(line);
	else if (!ft_strcmp(line[0], "sp"))
		i = check_args_sphere(line);
	else if (!ft_strcmp(line[0], "cy"))
		i = check_args_cylinder(line);
	return (i);
}

void	fill_scene(char **line, t_scene *scene)
{
	if (!ft_strcmp(line[0], "A"))
		scene->amb = fill_amb(line);
	else if (!ft_strcmp(line[0], "C"))
		scene->cam = fill_cam(line);
	else if (!ft_strcmp(line[0], "L"))
		scene->light = fill_light(line);
	else if (!ft_strcmp(line[0], "cy"))
		lstback_figure(&scene->figure, lstadd_figure(line, CYLINDER));
	else if (!ft_strcmp(line[0], "pl"))
		lstback_figure(&scene->figure, lstadd_figure(line, PLANE));
	else if (!ft_strcmp(line[0], "sp"))
		lstback_figure(&scene->figure, lstadd_figure(line, SPHERE));
}
