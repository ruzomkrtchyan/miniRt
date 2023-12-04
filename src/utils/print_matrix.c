#include "minirt.h"

void	print_matrix(t_matrix matrix)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			printf("%f ", matrix.m[i][j]);
		printf("\n");
	}
}