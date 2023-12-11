/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:45:33 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/06 21:46:47 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrix(t_matrix matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%f ", matrix.m[i][j]);
		printf("\n");
		i++;
	}
}
