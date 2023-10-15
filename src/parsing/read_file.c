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
	if (ft_strchr(res, '\t') != NULL)
	{
		write(2, "Error : Dont use tab\n", 22);
		free(res);
		exit(1);
	}
	if (!res)
	{
		write(2, "Erorr : File Empty\n", 20);
		exit(1);
	}
	return (res);
}
