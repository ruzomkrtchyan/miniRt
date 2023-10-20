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
		valid_float(vect) || valid_float(n_vect) || valid_coord(n_vect))
	{
		free_of_n(NULL, vect, n_vect, 2);
		free_2d(colors);
		return (err("Error : Wrong coordinates for plane\n"));
	}
	if (strlen_2d(colors) != 3 || valid_colors(colors))
	{
		free_of_n(NULL, vect, colors, 2);
		return (err("Error : Wrong colors for light\n"));
	}
	return (0 + free_of_n(NULL, vect, colors, 2));
}

int	check_args_sphere(char **line)
{
	char	**colors;
	char	**vect;
	char	**diam;

	diam = ft_split(line[2], '\n');
	if (valid_float(diam))
	{
		write(2, "Error : Wrong diameter for sphere\n", 35);
		diam = NULL;
		return (1);
	}
	free(diam);
	vect = ft_split(line[1], ',');
	if (strlen_2d(vect) != 3 || valid_float(vect))
	{
		write(2, "Error : Wrong coordinates for sphere\n", 35);
		free_2d(vect);
		return (1);
	}
	colors = ft_split(line[3], ',');
	if (strlen_2d(colors) != 3 || valid_colors(colors))
	{
		write(2, "Error : Wrong colors for sphere\n", 33);
		free_2d(vect);
		return (1);
	}
	return (0);
}

// int	check_args_cylinder(char **line)
// {

// }
