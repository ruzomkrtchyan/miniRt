/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:29:55 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/04 18:32:03 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

int	valid_float(char **str, int len)
{
	int	i;
	int	j;

	j = -1;
	while (++j < len)
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		if (str[j][i] == '.')
			return (1);
		i -= 1;
		while (str[j][++i])
			if (str[j][i] && ((str[j][i] < '0' || str[j][i] > '9') && \
														str[j][i] != '.'))
				return (1);
		i = -1;
		while (str[j][++i])
			if (str[j][i] == '.')
				break ;
		if (ft_strchr(str[j] + i + 1, '.') || \
				(str[j][i] == '.' && str[j][i + 1] == '\0'))
			return (1);
	}
	return (0);
}

int	valid_coord(char **arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (ft_atof(arr[i]) < -1.0 || ft_atof(arr[i]) > 1.0)
			return (1);
		i++;
	}
	return (0);
}
