/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:07:56 by vhovhann          #+#    #+#             */
/*   Updated: 2023/10/24 13:08:29 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*read_file(char *str)
{
	char	*tmp;
	char	*res;
	int		file;

	file = open(str, O_RDONLY);
	res = NULL;
	while (1)
	{
		tmp = get_next_line(file);
		if (!tmp)
			break ;
		if (!res)
			res = ft_strdup(tmp);
		else
			res = ft_strjoin(res, tmp, 1);
		free(tmp);
	}
	if (!res || ft_strchr(res, '\t') != NULL || only_new_line(res))
	{
		write(2, "Error : Incorrect file\n", 22);
		free(res);
		exit(1);
	}
	return (res);
}
