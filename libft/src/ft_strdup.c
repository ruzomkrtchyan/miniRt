/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:13:36 by vhovhann          #+#    #+#             */
/*   Updated: 2023/08/15 21:14:24 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*s;

	if (!str)
		return (0);
	len = 0;
	while (str && str[len])
		len++;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	len = 0;
	while (str[len])
	{
		s[len] = str[len];
		len++;
	}
	s[len] = '\0';
	return (s);
}
