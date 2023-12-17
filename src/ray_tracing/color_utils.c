/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:56:51 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/17 16:46:23 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	prod_col(t_rgb c1, t_rgb c2, float ratio)
{
	t_rgb	new;

	new.r = c1.r * (c2.r / 255) * ratio;
	new.g = c1.g * (c2.g / 255) * ratio;
	new.b = c1.b * (c2.b / 255) * ratio;
	return (new);
}

t_rgb	add_col(t_rgb c1, t_rgb c2)
{
	t_rgb	new;

	new.r = c1.r + c2.r;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g + c2.g;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b + c2.b;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_rgb	n_prod_col(t_rgb c, float n)
{
	t_rgb	new;

	new.r = n * c.r;
	new.g = n * c.g;
	new.b = n * c.b;
	return (new);
}
