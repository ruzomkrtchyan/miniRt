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
	if (!str)
		return (0);
	while (str && str[i] != NULL)
		i++;
	return (i);
}

int	free_of_n(char *str, char **arr1, char **arr2, int i)
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
		if (str != NULL)
			free(str);
		if (arr1 != NULL)
			free_2d(arr1);
		if (arr2 != NULL)
			free_2d(arr2);
	}
	else
		free(str);
	return (0);
}
