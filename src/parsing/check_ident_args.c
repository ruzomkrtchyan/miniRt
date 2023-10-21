#include "minirt.h"

int	check_args_amb(char **line)
{
	char	**colors;
	char	*amb;

	amb = ft_strdup(line[1]);
	colors = NULL;
	if (valid_float(&amb, 1) || ft_atof(line[1]) < 0.0 || ft_atof(line[1]) > 1.0)
	{
		free(amb);
		return (err("Error : Ambient light factor is not in range\n"));
	}
	free(amb);
	colors = ft_split(line[2], ',');
	if (strlen_2d(colors) != 3)
	{
		free_2d(colors);
		return(err("Error : Color arguments do not match quantity\n"));
	}
	if (valid_colors(colors))
	{
		free_2d(colors);	
		return (err("Error : Color number out of range\n"));
	}
	free_2d(colors);
	return (0);
}

int	check_args_cam(char **line)
{
	int		fov;
	char	**n_vect;
	char	**vect;

	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	fov = ft_atoi(line[3]);
	if (strlen_2d(vect) != 3 || strlen_2d(n_vect) != 3)
	{
		free_of_n(NULL, vect, n_vect, 2);
		return (err("Error : wrong coordinates for camera\n"));
	}
	if (fov < 0 || fov > 180)
	{
		free_of_n(NULL, vect, n_vect, 2);
		return (err("Field of view out of range\n"));
	}
	free_of_n(NULL, vect, n_vect, 2);
	return (0);
}

int	check_args_light(char **line)
{
	char	**vect;
	char	**colors;
	char	*light;

	vect = ft_split(line[1], ',');
	colors = ft_split(line[3], ',');
	light = ft_strdup(line[2]);
	if (strlen_2d(vect) != 3)
	{
		free_of_n(light, vect, colors, 3);
		return (err("Error : Wrong coordinates for light\n"));
	}
	if (strlen_2d(colors) != 3 || valid_colors(colors))
	{
		free_of_n(light, vect, colors, 3);
		return (err("Error : Wrong colors for light\n"));
	}
	if (valid_float(&light, 1) || ft_atof(line[2]) < 0.0 || ft_atof(line[2]) > 1.0)
	{
		free_of_n(light, vect, colors, 2);
		return (err("\nError : Wrong brightnes for light\n\n"));
	}
	free_of_n(light, vect, colors, 2);
	return (0);
}
