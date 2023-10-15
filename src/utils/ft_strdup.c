/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vache <vache@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:13:36 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/12 12:10:06 by vache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*s;

	if (!str)
		return (0);
	len = 0;
	while (str && str[len])
		len++;
	s = (char *)ft_calloc(len + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	while (len >= 0)
	{
		s[len] = str[len];
		len--;
	}
	return (s);
}
