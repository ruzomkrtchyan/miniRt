/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vache <vache@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:55:00 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/12 14:11:45 by vache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	char	*res;
	char	**arr;

	res = NULL;
	arr = NULL;
	if (argc != 2)
	{
		write(2, "Error : Arguments\n", 19);
		return (1);
	}
	check_fname(argv[1]);
	res = read_file(argv[1]);
	arr = ft_split(res, '\n');
	free(res);
	check_ident_name(arr);
	pars(arr);
	free_2d(arr);
	return (0);
}
