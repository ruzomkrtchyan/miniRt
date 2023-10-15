#include "minirt.h"

void	check_fname(char *str)
{
	if (ft_strrchr(str, '.'))
	{
		if (ft_strcmp(ft_strrchr(str, '.'), ".rt"))
		{
			write(2, "Error : File type\n", 19);
			exit(1);
		}
	}
	else
	{
		write(2, "Error : File type\n", 19);
		exit(1);
	}
}