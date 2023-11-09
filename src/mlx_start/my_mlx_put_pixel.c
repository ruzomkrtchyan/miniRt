/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:13:24 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/09 11:14:20 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->line_length + x * \
										(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
