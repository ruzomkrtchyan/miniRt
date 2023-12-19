/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:07:45 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/19 15:32:46 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_identifier(char **arr);
int	check_identifier2(char **arr);
int	check_identifier3(char **arr);

int	check_identifier(char **arr)
{
	if (!ft_strcmp(arr[0], "A"))
	{
		if (strlen_2d(arr) != 3)
			return (err("Error : Wrong 'A' identifier arguments\n"));
	}
	else if (check_identifier2(arr) == 1 || check_identifier3(arr) == 1)
		return (1);
	else if (check_identifier2(arr) == 2 && check_identifier3(arr) == 2)
		return (err("Error : Wrong identifier\n"));
	return (0);
}

int	check_identifier2(char **arr)
{
	if (!ft_strcmp(arr[0], "C"))
	{
		if (strlen_2d(arr) != 4)
			return (err("Error : Wrong 'C' identifier arguments\n"));
	}
	else if (!ft_strcmp(arr[0], "L"))
	{
		if (strlen_2d(arr) != 4)
			return (err("Error : Wrong 'L' identifier arguments\n"));
	}
	else
		return (2);
	return (0);
}

int	check_identifier3(char **arr)
{
	if (!ft_strcmp(arr[0], "pl"))
	{
		if (strlen_2d(arr) < 5 || strlen_2d(arr) > 6)
			return (err("Error : Wrong 'pl' identifier arguments\n"));
	}
	else if (!ft_strcmp(arr[0], "sp"))
	{
		if (strlen_2d(arr) < 5 || strlen_2d(arr) > 6)
			return (err("Error : Wrong 'sp' identifier arguments\n"));
	}
	else if (!ft_strcmp(arr[0], "cy"))
	{
		if (strlen_2d(arr) < 7 || strlen_2d(arr) > 8)
			return (err("Error : Wrong 'cy' identifier arguments\n"));
	}
	else if (!ft_strcmp(arr[0], "co"))
	{
		if (strlen_2d(arr) < 8 || strlen_2d(arr) > 9)
			return (err("Error : Wrong 'co' identifier arguments\n"));
	}
	else
		return (2);
	return (0);
}
