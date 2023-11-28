/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transver_scale_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:51:59 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/28 18:56:23 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	scale_matrix(int sx, int sy, int sz);
t_matrix	move_matrix(int dx, int dy, int dz);

t_matrix	scale_matrix(int dx, int dy, int dz)
{
	t_matrix	out_m;

	out_m = new_zero_matrix();
	out_m.m[0][0] = 1;
	out_m.m[0][3] = dx;
	out_m.m[1][1] = 1;
	out_m.m[1][3] = dy;
	out_m.m[2][2] = 1;
	out_m.m[2][3] = dz;
	out_m.m[3][3] = 1;
	return (out_m);
}

t_matrix	move_matrix(int sx, int sy, int sz)
{
	t_matrix	out_m;

	out_m = new_zero_matrix();
	out_m.m[0][0] = sx;
	out_m.m[1][1] = sy;
	out_m.m[2][2] = sz;
	out_m.m[3][3] = 1;
	return (out_m);
}
