/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:55:00 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/06 18:41:56 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	char	*res;
	char	**arr;
	t_scene	*scene;

	res = NULL;
	arr = NULL;
	scene = NULL;
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
	scene = pars(arr, scene);
	free_2d(arr);
	sort_obj_list(scene);
	mlx_create(scene);
	destroy_scene(&scene);
	return (0);
}
