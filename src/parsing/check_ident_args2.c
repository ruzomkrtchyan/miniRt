#include "minirt.h"

int	check_args_plane(char **line);
int	check_args_sphere(char **line);
int	check_args_cylinder(char **line);
int	check_args_cylinder_2(char **line);

int	check_args_plane(char **line)
{
	char	**vect;
	char	**n_vect;
	char	**colors;

	vect = ft_split(line[1],',');
	n_vect = ft_split(line[2],',');
	colors = ft_split(line[3],',');
	if (strlen_2d(vect) != 3 || strlen_2d(n_vect) != 3 || \
		valid_float(vect, 3) || valid_float(n_vect, 3) || valid_coord(n_vect))
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
	free_of_n(NULL, vect, colors, 2);
	return (0);
}

int	check_args_sphere(char **line)
{
	char	**colors;
	char	**vect;
	char	*diam;

	diam = ft_strdup(line[2]);
	vect = ft_split(line[1], ',');
	colors = ft_split(line[3], ',');
	if (valid_float(&diam, 1))
	{
		free_of_n(diam, vect, colors, 3);
		return (err("Error : Wrong diameter for sphere\n"));
	}
	if (strlen_2d(vect) != 3 || valid_float(vect, 3))
	{
		free_of_n(diam, vect, colors, 3);
		return (err("Error : Wrong coordinates for sphere\n"));
	}
	if (strlen_2d(colors) != 3 || valid_colors(colors))
	{
		free_of_n(diam, vect, colors, 3);
		return (err("Error : Wrong colors for sphere\n"));
	}
	free_of_n(diam, vect, colors, 3);
	return (0);
}

int	check_args_cylinder(char **line)
{
	char	**vect;
	char	**n_vect;
	char	*diam;

	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	diam = ft_strdup(line[3]);
	if (strlen_2d(vect) != 3 || strlen_2d(n_vect) != 3 || \
		valid_float(vect, 3) || valid_float(n_vect, 3) || valid_coord(n_vect))
	{
		free_of_n(diam, vect, n_vect, 3);
		return (err("Error : Wrong coordinates for cylinder\n"));
	}
	if (valid_float(&diam, 1))
	{
		free_of_n(diam, vect, n_vect, 3);
		return (err("Error : Wrong diameter for cylinder\n"));
	}
	free_of_n(diam, vect, n_vect, 3);
	if (check_args_cylinder_2(line))
		return (1);
	return (0);
}

int	check_args_cylinder_2(char **line)
{
	char	**colors;
	char	*height;

	height = ft_strdup(line[4]);
	if (valid_float(&height, 1))
	{
		free(height);
		return (err("Error : Wrong height for cylinder\n"));
	}
	free(height);
	colors = ft_split(line[5], ',');
	if (strlen_2d(colors) != 3 || valid_colors(colors))
	{
		free_2d(colors);
		return (err("Error : Wrong colors for cylinder\n"));
	}
	free_2d(colors);
	return (0);
}
