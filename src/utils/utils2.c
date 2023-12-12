/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:37 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/11 19:08:03 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_matrix_num(char **arr);

int	check_number(char *str, char **arr, int mode)
{
	int	i;

	i = 0;
	if (mode)
	{
		if (str && str[i] && (str[i] == '-' || str[i] == '+'))
			i++;
		while (str && str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
			i++;
		}
	}
	else if (!mode)
		return (check_matrix_num(arr));
	return (0);
}

int	check_matrix_num(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] == '-' || arr[i][j] == '+')
			j++;
		while (arr[i][j])
		{
			if (arr[i][j] != '.' && (arr[i][j] < '0' || arr[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
