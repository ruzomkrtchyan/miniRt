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

void	check_A(char *str)
{
	int	i;

	i = 1;
	if (str[i] != " ")
	{
		write (2, "Error: Wrong Identifier\n", 24);
		exit (1);
	}
	else
	{
		while ( str[i] && str[i] == " ")
			i++;
		
	}
}