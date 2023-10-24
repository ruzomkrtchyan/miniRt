/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ident_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:07:51 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/24 13:28:31 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args_amb(char **line);
int	check_args_cam(char **line);
int	check_args_light(char **line);

int	check_args_amb(char **line)
{
	char	**colors;
	char	*amb;

	amb = ft_strdup(line[1]);
	if (valid_float(&amb, 1) || ft_atof(line[1]) < 0.0 || \
				ft_atof(line[1]) > 1.0 || count_comma(line[1]) != 0)
	{
		free(amb);
		return (err("Error : Ambient light factor is not in range\n"));
	}
	free(amb);
	colors = ft_split(line[2], ',');
	if (count_comma(line[2]) != 2 || check_number(NULL, colors, 0) || \
												strlen_2d(colors) != 3)
	{
		free_2d(colors);
		return (err("Error : Wrong RGB number\n"));
	}
	if (valid_colors(colors))
	{
		free_2d(colors);
		return (err("Error : Color number is out of range\n"));
	}
	free_2d(colors);
	return (0);
}

int	check_args_cam(char **line)
{
	int		fov;
	char	**vect;
	char	**n_vect;

	vect = ft_split(line[1], ',');
	n_vect = ft_split(line[2], ',');
	fov = ft_atoi(line[3]);
	if (count_comma(line[1]) != 2 || count_comma(line[2]) != 2 || \
			valid_coord(n_vect) || check_number(NULL, vect, 0) || \
			check_number(NULL, n_vect, 0) || strlen_2d(vect) != 3 || \
				strlen_2d(n_vect) != 3)
	{
		free_of_n(NULL, vect, n_vect, 2);
		return (err("Error : Wrong coordinates for camera\n"));
	}
	free_of_n(NULL, vect, n_vect, 2);
	if (fov < 0 || fov > 180 || count_comma(line[3]) != 0 || \
									check_number(line[3], NULL, 1))
		return (err("Error : The field of view is out of range\n"));
	return (0);
}

int	check_args_light(char **line)
{
	char	**colors;
	char	**vect;

	vect = ft_split(line[1], ',');
	if (count_comma(line[1]) != 2 || strlen_2d(vect) != 3 || \
									check_number(NULL, vect, 0))
		return (err("Error : Wrong coordinates for light\n") + free_2d(vect));
	free_2d(vect);
	colors = ft_split(line[3], ',');
	if (valid_float(&line[2], 1) || ft_atof(line[2]) < 0.0 || \
		ft_atof(line[2]) > 1.0 || count_comma(line[2]) != 0)
	{
		free_2d(colors);
		return (err("Error : Wrong brightnes for light\n"));
	}
	if (count_comma(line[3]) != 2 || valid_colors(colors) || \
			strlen_2d(colors) != 3 || check_number(NULL, colors, 1))
	{
		free_2d(colors);
		return (err("Error : Wrong colors for light\n"));
	}
	free_2d(colors);
	return (0);
}
