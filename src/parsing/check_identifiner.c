#include "minirt.h"

int	check_identifier_name(char *str);
int	check_identifier(char **arr);
int	check_identifier2(char **arr);
int	check_identifier3(char **arr);

int	check_identifier_name(char *str)
{
	if (!ft_strcmp(str, "A") || !ft_strcmp(str, "C") || \
		!ft_strcmp(str, "L") || !ft_strcmp(str, "pl") || \
		!ft_strcmp(str, "sp") || !ft_strcmp(str, "cy"))
		return (0);
	write(2, "Error : All identifiers are not present\n", 41);
	return (1);
}

int	check_identifier(char **arr)
{
	if (!ft_strcmp(arr[0], "A"))
	{
		if (strlen_2d(arr) != 3)
		{
			write(2, "Error : Wrong 'A' identifier arguments\n", 40);
			return (1);
		}
	}
	else if (check_identifier2(arr) || check_identifier3(arr))
		return (1);
	return (0);
}

int	check_identifier2(char **arr)
{
	if (!ft_strcmp(arr[0], "C"))
	{
		if (strlen_2d(arr) != 4)
		{
			write(2, "Error : Wrong 'C' identifier arguments\n", 40);
			return (1);
		}
	}
	else if (!ft_strcmp(arr[0], "L"))
	{
		if (strlen_2d(arr) != 4)
		{
			write(2, "Error : Wrong 'L' identifier arguments\n", 40);
			return (1);
		}
	}
	else if (!ft_strcmp(arr[0], "L"))
	{
		if (strlen_2d(arr) != 4)
		{
			write(2, "Error : Wrong 'L' identifier arguments\n", 40);
			return (1);
		}
	}
	return (0);
}

int	check_identifier3(char **arr)
{
	if (!ft_strcmp(arr[0], "pl"))
	{
		if (strlen_2d(arr) != 4)
		{
			write(2, "Error : Wrong 'pl' identifier arguments\n", 41);
			return (1);
		}
	}
	else if (!ft_strcmp(arr[0], "sp"))
	{
		if (strlen_2d(arr) != 4)
		{
			write(2, "Error : Wrong 'sp' identifier arguments\n", 41);
			return (1);
		}
	}
	else if (!ft_strcmp(arr[0], "cy"))
	{
		if (strlen_2d(arr) != 6)
		{
			write(2, "Error : Wrong 'cy' identifier arguments\n", 41);
			return (1);
		}
	}
	return (0);
}
