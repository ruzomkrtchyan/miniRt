/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:07:43 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/21 14:51:37 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_fname(char *str);
void	check_ident_name(char **arr);

void	check_fname(char *str)
{
	if (ft_strrchr(str, '.'))
	{
		if (ft_strcmp(ft_strrchr(str, '.'), ".rt"))
		{
			write(2, "Error : File type\n", 19);
			exit(1);
		}
	}
	else
	{
		write(2, "Error : File type\n", 19);
		exit(1);
	}
}

void	check_ident_name(char **arr)
{
	int	a;
	int	c;
	int	i;

	i = 0;
	a = 0;
	c = 0;
	while (arr[i])
	{
		if (arr[i][0] == 'A')
			a++;
		else if (arr[i][0] == 'C')
			c++;
		else if (arr[i][0] == ' ')
			exit(err("Error : Invalid file\n") + free_2d(arr));
		i++;
	}
	if (a > 1 || c > 1)
		exit(err("Error : Wrong quantity of Identifiers\n") + free_2d(arr));
}
