/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:48 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/19 14:19:16 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	checkerboard(t_scene *scene, float t)
{
	t_vect	p;
	t_vect	new;
	int		black;
	int		white;
	int		mix;
	
	black = 0x000000;
	white = 0xffffff;
	p = sum_vect(scene->cam->pos, num_product_vect(scene->ray, t));
	new.x = fabsf(floorf(p.x * 2));
	new.y = fabsf(floorf(p.y * 2));
	new.z = fabsf(floorf(p.z * 2));
	if ((fmodf(new.x, 2) == 0 && fmodf(new.y, 2) == 0 ) || (fmodf(new.x, 2) != 0 && fmodf(new.y, 2) != 0))
	{
		if (fmodf(new.z, 2) != 0)
			mix = 1;
		else
			mix = 0;
	}
	else
		mix = 0;
	if (mix)
		return (black);
	else
		return (white);
}