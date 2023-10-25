/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:35 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/10/25 18:40:02 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <fcntl.h>
# include "structs.h"
# include "libft.h"
# include "get_next_line_bonus.h"

# define W 		13
# define A 		0
# define S 		1
# define D 		2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define ESC	53

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
void	destroy_scene(t_scene **scene);

t_scene	*pars(char **arr, t_scene *scene);
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

void	mlx_create(t_scene *scene);

#endif