#include "minirt.h"


void pars(char **arr)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	line = NULL;
	while (arr[i])
	{
		j = 0;
		line = ft_split(arr[i], ' ');
		if (check_identifier(line) || check_ident_args(line))
		{
			free_2d(arr);
			exit(1);
		}
		free_2d(line);
		i++;
	}

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
	// else if (!ft_strcmp(line[0], "cy"))
	// 	i = check_args_cylinder(line);
	return (i);
}