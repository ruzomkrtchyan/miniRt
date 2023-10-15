/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vache <vache@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:54:48 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/12 12:10:02 by vache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strrchr( char *str, int c)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	s = (char *)str;
	i = ft_strlen(str);
	while (*s)
		s++;
	while (i >= 0)
	{
		if (*s == c % 256)
			return (s);
		s--;
		i--;
	}
	return (NULL);
}
