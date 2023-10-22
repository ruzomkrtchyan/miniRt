#include "minirt.h"

void	pars(char **arr);
int		check_ident_args(char **line);
void	fill_structs(char **line, t_scene *scene);

void pars(char **arr)
{
	int		i;
	t_scene	*scene;
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
	scene = (t_scene *)malloc(sizeof(scene));
	if (!scene)
		exit(1);
	// i = -1;
	// while (arr[++i])
	// {
	// 	line = ft_split(arr[i], ' ');
	// 	fill_structs(line, scene);
	// 	free_2d(line);
	// }
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
		scene->cam = fill_light(line);
	else if (!ft_strcmp(line[0], "pl"))
		fill_plane(line, scene->pl);
	else if (!ft_strcmp(line[0], "sp"))
		lstback_sp(&scene->sph, lstadd_sp(line));
	else if (!ft_strcmp(line[0], "cy"))
		fill_cylinder(line, scene->cyl);
}
