#include "minirt.h"

void	check_fname(char *str);
void	check_ident_name(char **arr);

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
	int	l;

	i = 0;
	a = 0;
	c = 0;
	l = 0;
	while (arr[i])
	{
		if (arr[i][0] == 'A')
			a++;
		else if (arr[i][0] == 'C')
			c++;
		else if (arr[i][0] == 'L')
			l++;
		else if (arr[i][0] == ' ')
			exit(err("Error : Invalid file\n") + free_2d(arr));
		i++;
	}
	if (a == 0 || c == 0)
		exit(err("Error : Ambient or Camera is not defined\n") + free_2d(arr));
	if (a != 1 || c != 1 || l != 1)
		exit(err("Error : Wrong quantity of Identifiers\n") + free_2d(arr));
}
