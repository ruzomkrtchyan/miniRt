/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:35 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/23 16:16:02 by vhovhann         ###   ########.fr       */
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
	t_vect	*coord;
	t_rgb	*color;
	float	bright;
}				t_light;

typedef	struct s_sph
{
	float			diam;
	t_vect			*coord;
	t_rgb			*color;
	struct s_sph	*next;
	struct s_sph	*prev;
}				t_sph;

typedef	struct s_pl
{
	t_vect		*coord;
	t_vect		*n_coord;
	t_rgb		*color;
	struct s_pl	*next;
	struct s_pl	*prev;
}				t_pl;

typedef	struct s_cyl
{
	t_vect			*coord;
	t_vect			*n_coord;
	t_rgb			*color;
	float			diam;
	float			height;
	struct s_cyl	*next;
	struct s_cyl	*prev;
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

void	print_vect(char **arr);

/*************************************/
/**************UTILS******************/
/*************************************/

int		free_of_n(char *str, char **arr1, char **arr2, int i);
float	ft_atof(char *str);
int		strlen_2d(char **str);
int		free_2d(char **s);
int		err(char *str);
int		only_new_line(char *str);
int		count_comma(char *str);
int		check_number(char *str, char **arr, int mode);
int		valid_coord(char **arr);
int		valid_float(char **str, int len);
int		valid_colors(char **colors);
char	*read_file(char *str);
t_scene	*scene_init(t_scene *scene);

void	pars(char **arr, t_scene *scene);;
void	check_fname(char *str);
void	check_ident_name(char **arr);
int		check_identifier(char **arr);
int		check_ident_args(char **arr);
int		check_args_amb(char **line);
int		check_args_cam(char **line);
int		check_args_light(char **line);
int		check_args_plane(char **line);
int		check_args_sphere(char **line);
int		check_args_cylinder(char **line);

/***********************************************/
/**************LST_UTILS_SPHERE*****************/
/***********************************************/

void	lstback_sp(t_sph **pars, t_sph *new);
void	lstclear_sp(t_sph **lst);
int		lstsize_sp(t_sph *lst);
t_sph	*lstadd_sp(char **line);
t_sph	*lstlast_sp(t_sph *lst);

t_amb	*fill_amb(char **line);
t_cam	*fill_cam(char **line);
t_light	*fill_light(char **line);

void	lstback_pl(t_pl **pars, t_pl *new);
void	lstclear_pl(t_pl **lst);
int		lstsize_pl(t_pl *lst);
t_pl	*lstadd_pl(char **line);
t_pl	*lstlast_pl(t_pl *lst);

void	lstback_cyl(t_cyl **pars, t_cyl *new);
void	lstclear_cyl(t_cyl **lst);
int		lstsize_cyl(t_cyl *lst);
t_cyl	*lstadd_cyl(char **line);

void	lstback_sp(t_sph **pars, t_sph *new);
void	lstclear_sp(t_sph **lst);
int		lstsize_sp(t_sph *lst);
t_sph	*lstadd_sp(char **line);
t_sph	*lstlast_sp(t_sph *lst);

#endif