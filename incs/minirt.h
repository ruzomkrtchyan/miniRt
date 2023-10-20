/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vache <vache@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:35 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/12 13:52:36 by vache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdint.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line_bonus.h"

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef	struct s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef	struct s_light
{
	t_vect	*cord;
	t_rgb	*color;
	float	bright;
}				t_light;

typedef	struct s_sph
{
	t_vect	*cord;
	t_rgb	*color;
	float	diam;
}				t_sph;

typedef	struct s_pl
{
	t_vect	*cord;
	t_vect	*n_cord;
	t_rgb	*color;
}				t_pl;

typedef	struct s_cyl
{
	t_vect	*cord;
	t_vect	*n_cord;
	t_rgb	*color;
	float	diam;
	float	height;
}				t_cyl;

typedef	struct s_amb
{
	float	ratio;
	t_rgb	*color;
}				t_amb;

typedef struct s_cam
{
	t_vect	*dir;
	t_vect	*pos;
	float	degree;
}				t_cam;

typedef	struct s_scene
{
	t_amb	*amb;
	t_light	*light;
	t_sph	*sph;
	t_pl	*pl;
	t_cyl	*cyl;
	t_cam	*cam;
}				t_scene;

typedef	struct s_pars
{
	char	*str;
	float	amb;
	float	l_brith;
	float	s_diam;
	float	c_diam;
	float	c_height;
	t_vect	*coord;
	t_vect	*n_vect;
	t_rgb	*color;
}				t_pars;

/*************************************/
/**************UTILS******************/
/*************************************/

int		free_of_n(char *str, char **arr1, char **arr2, int i);
float	ft_atof(char *str);
int		strlen_2d(char **str);
int		free_2d(char **s);
int		err(char *str);

void	check_fname(char *str);
void	check_ident_name(char **arr);
char	*read_file(char *str);
void 	pars(char **arr);
int		check_identifier(char **arr);
int		check_ident_args(char **arr);
int		check_args_amb(char **line);
int		check_args_cam(char **line);
int		check_args_light(char **line);
int		check_args_plane(char **line);

#endif