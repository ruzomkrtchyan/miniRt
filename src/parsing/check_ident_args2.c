#include "minirt.h"

int	check_args_plane(char **line)
{
	char	**vect;
	char	**n_vect;
	char	**colors;

	vect = ft_split(line[1],',');
	n_vect = ft_split(line[2],',');
	colors = ft_split(line[3],',');
	if (strlen_2d(vect) != 3 || strlen_2d(n_vect) != 3 || \
		(ft_atof(n_vect[0]) < 0.0 || ft_atof(n_vect[0]) > 1) || \
		(ft_atof(n_vect[1]) < 0.0 || ft_atof(n_vect[1]) > 1.0) || \
		(ft_atof(n_vect[2]) < 0.0 || ft_atof(n_vect[2]) > 1.0))
	{
		free_of_n(NULL, vect, n_vect, 2);
		free_2d(colors);
		return (err("Error : Wrong coordinates for plane\n"));
	}
	if (strlen_2d(colors) != 3 || \
		(ft_atoi(colors[0]) < 0 || ft_atoi(colors[0]) > 255) || \
		(ft_atoi(colors[1]) < 0 || ft_atoi(colors[1]) > 255) || \
		(ft_atoi(colors[2]) < 0 || ft_atoi(colors[2]) > 255))
	{
		free_of_n(NULL, vect, colors, 2);
		return (err("Error : Wrong colors for light\n"));
	}
	return (0 + free_of_n(NULL, vect, colors, 2));
}

// int	check_args_sphere(char **line)
// {

// }

// int	check_args_cylinder(char **line)
// {

// }
