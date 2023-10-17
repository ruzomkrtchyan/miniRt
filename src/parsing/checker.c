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
	int		i;
	int		first;
	char	*tmp;
	t_pars	*res;

	i = 1;
	res = (t_pars *)malloc(sizeof(t_pars));
	res->c = str[0];
	tmp = NULL;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
			first = i;
		while (str[i] && str[i] != ' ')
			i++;
		tmp = ft_substr(str, first, i);
	}
	// if (str[i] != " ")
	// {
	// 	write (2, "Error: Wrong Identifier\n", 24);
	// 	exit (1);
	// }
	// else
	// {
	// 	while ( str[i] && str[i] == " ")
	// 		i++;
	// }
}