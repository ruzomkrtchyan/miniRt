#include "minirt.h"

int	err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}