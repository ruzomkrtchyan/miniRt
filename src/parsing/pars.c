/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:07:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/31 12:48:41 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*pars(char **arr, t_scene *scene);
int		check_ident_args(char **line);
void	fill_structs(char **line, t_scene *scene);

void	init_scene(t_scene **scene)
{
	(*scene)->amb = NULL;
	(*scene)->light = NULL;
	(*scene)->sph = NULL;
	(*scene)->pl = NULL;
	(*scene)->cyl = NULL;
	(*scene)->cam = NULL;
	(*scene)->data = NULL;
	(*scene)->mlx = NULL;
}

t_scene	*pars(char **arr, t_scene *scene)
{
	int		i;
	char	**line;

	line = NULL;
	i = -1;
	while (arr[++i])
	{
		line = ft_split(arr[i], ' ');
		if (check_identifier(line) || check_ident_args(line))
			exit(1 + free_of_n(NULL, line, arr, 2));
		free_2d(line);
	}
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(&scene);
	i = -1;
	while (arr[++i])
	{
		line = ft_split(arr[i], ' ');
		fill_structs(line, scene);
		free_2d(line);
	}
	scene->height = 1080;
	scene->width = 720;
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

void	fill_structs(char **line, t_scene *scene)
{
	if (!ft_strcmp(line[0], "A"))
		scene->amb = fill_amb(line);
	else if (!ft_strcmp(line[0], "C"))
		scene->cam = fill_cam(line);
	else if (!ft_strcmp(line[0], "L"))
		scene->light = fill_light(line);
	else if (!ft_strcmp(line[0], "pl"))
		lstback_pl(&scene->pl, lstadd_pl(line));
	else if (!ft_strcmp(line[0], "sp"))
		lstback_sp(&scene->sph, lstadd_sp(line));
	else if (!ft_strcmp(line[0], "cy"))
		lstback_cyl(&scene->cyl, lstadd_cyl(line));
}
