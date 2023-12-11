/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:39 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/11 17:32:59 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	get_rotation_z(float angle);
t_matrix	get_rotation_y(float angle);
t_matrix	get_rotation_x(float angle);

t_matrix	get_rotation_x(float angle)
{
	t_matrix	out_m;
	float		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = 1;
	out_m.m[1][1] = cos(rad);
	out_m.m[1][2] = -sin(rad);
	out_m.m[2][1] = sin(rad);
	out_m.m[2][2] = cos(rad);
	return (out_m);
}

t_matrix	get_rotation_y(float angle)
{
	t_matrix	out_m;
	float		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = cos(rad);
	out_m.m[0][2] = sin(rad);
	out_m.m[1][1] = 1;
	out_m.m[2][0] = -sin(rad);
	out_m.m[2][2] = cos(rad);
	out_m.m[3][3] = 1;
	return (out_m);
}

t_matrix	get_rotation_z(float angle)
{
	t_matrix	out_m;
	float		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = cos(rad);
	out_m.m[0][1] = -sin(rad);
	out_m.m[1][0] = sin(rad);
	out_m.m[1][1] = cos(rad);
	out_m.m[2][2] = 1;
	out_m.m[3][3] = 1;
	return (out_m);
}
