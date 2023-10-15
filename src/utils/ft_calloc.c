/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vache <vache@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:53:13 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/12 12:18:31 by vache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;

	if (nitems == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nitems * size));
	return (ptr);
}
