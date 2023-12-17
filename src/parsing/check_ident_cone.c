/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ident_cone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:34:41 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/17 17:59:12 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args_cone(char **line);
int	check_args_cone_2(char **line);

int	check_args_cone(char **line)
{
	char	**vect;
	char	**axis;
	char	*radius;

	vect = ft_split(line[1], ',');
	axis = ft_split(line[2], ',');
	radius = ft_strdup(line[3]);
	if (count_comma(line[1]) != 2 || count_comma(line[2]) != 2 || \
			strlen_2d(vect) != 3 || strlen_2d(axis) != 3 || \
		valid_float(vect, 3) || valid_float(axis, 3) || valid_coord(axis))
	{
		free_of_n(radius, vect, axis, 3);
		return (err("Error : Wrong coordinates for cone\n"));
	}
	if (valid_float(&radius, 1) || count_comma(line[3]) != 0)
	{
		free_of_n(radius, vect, axis, 3);
		return (err("Error : Wrong radius for cone\n"));
	}
	free_of_n(radius, vect, axis, 3);
	if (check_args_cone_2(line))
		return (1);
	return (0);
}

int	check_args_cone_2(char **line)
{
	char	**colors;
	char	*height;

	height = ft_strdup(line[4]);
	if (valid_float(&height, 1) || count_comma(line[4]) != 0)
	{
		free(height);
		return (err("Error : Wrong height for cone\n"));
	}
	free(height);
	colors = ft_split(line[7], ',');
	if (strlen_2d(colors) != 3 || valid_colors(colors) || \
			count_comma(line[7]) != 2 || check_number(NULL, colors, 0))
	{
		free_2d(colors);
		return (err("Error : Wrong colors for cone\n"));
	}
	free_2d(colors);
	return (0);
}