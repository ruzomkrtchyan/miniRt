#include "minirt.h"

float	after_dot(char *str)
{
	int	i;
	float	res;

	i = 0;
	res = 0.0;
	while (str[i])
	{
		res = res * 10.0 + str[i] - '0';
		i++;
	}
	while (i--)
		res /= 10;
	return (res);
}

float	before_dot(char *str)
{
	int		i;
	float	res;

	i = 0;
	res = 0.0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
	
}

void	valid_float(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			i++;
		else
		{
			write(2, "Error : incorrect float number\n", 32);
			exit(1);
		}
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			break;
	}
	if (ft_strchr(str + i + 1, '.') || !ft_strchr(str, '.') || (str[i] == '.' && i == 0))
	{
		write(2, "Error: incorrect dots\n", 23);
		exit(1);
	}
}

float	ft_atof(char *str)
{
	float	res;
	int		i;
	float	sign;

	res = 0;
	i = 0;
	sign = 1.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		++str;
	}
	valid_float(str);
	res = before_dot(str);
	while (str[i] && str[i] != '.')
		i++;
	res += after_dot(str + i + 1);
	return (res * sign);
}
