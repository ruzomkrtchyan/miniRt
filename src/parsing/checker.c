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

void	check_ident_name(char **arr)
{
	int	a;
	int	c;
	int	i;

	i = 0;
	a = 0;
	c = 0;
	while (arr[i])
	{
		if (arr[i][0] == 'A' && arr[i][1] == ' ')
			a++;
		else if (arr[i][0] == 'C' && arr[i][1] == ' ')
			c++;
		i++;
	}
	if (a == 0 || c == 0)
	{
		write(2, "Error : Ambient light or Camera is not defined\n", 48);
		free_2d(arr);
		exit(1);
	}
}
