#include "minirt.h"

int	free_of_n(char *str, char **arr1, char **arr2, int i);

int	free_2d(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
		free (s[i++]);
	free(s);
	return (0);
}

int	strlen_2d(char **str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return (0);
	while (str && str[i] != NULL)
		i++;
	return (i);
}

int	free_of_n(char **arr1, char **arr2, char **arr3, int i)
{
	if (i == 2)
	{
		if (arr1 != NULL)
			free_2d(arr1);
		if (arr2 != NULL)
			free_2d(arr2);
	}
	else if (i == 3)
	{
		if (arr1 != NULL)
			free_2d(arr1);
		if (arr2 != NULL)
			free_2d(arr2);
		if (arr3 != NULL)
			free_2d(arr3);
	}
	return (0);
}

int	only_new_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	count_comma(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

void	print_vect(char **arr)
{
	for (int i = 0; arr[i]; ++i)
		printf("%s\n", arr[i]);
}