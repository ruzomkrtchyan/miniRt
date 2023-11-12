/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:35 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/11/12 12:50:24 by rmkrtchy         ###   ########.fr       */
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
# define HEIGHT	1080
# define WIDTH	1920

/*************************************/
/**************UTILS******************/
/*************************************/

int			free_of_n(char *str, char **arr1, char **arr2, int i);
float		ft_atof(char *str);
int			strlen_2d(char **str);
int			free_2d(char **s);
int			err(char *str);
int			only_new_line(char *str);
int			count_comma(char *str);
int			check_number(char *str, char **arr, int mode);
int			valid_coord(char **arr);
int			valid_float(char **str, int len);
int			valid_colors(char **colors);
char		*read_file(char *str);
void		destroy_scene(t_scene **scene);

t_scene		*pars(char **arr, t_scene *scene);
void		check_fname(char *str);
void		check_ident_name(char **arr);
int			check_identifier(char **arr);
int			check_ident_args(char **arr);
int			check_args_amb(char **line);
int			check_args_cam(char **line);
int			check_args_light(char **line);
int			check_args_plane(char **line);
int			check_args_sphere(char **line);
int			check_args_cylinder(char **line);

/***********************************************/
/**************LST_UTILS_SPHERE*****************/
/***********************************************/

t_amb		*fill_amb(char **line);
t_cam		*fill_cam(char **line);
t_light		*fill_light(char **line);

t_pl		*init_pl(char **line);
t_cyl		*init_cyl(char **line);
t_sph		*init_sp(char **line);

int			lstsize_figure(t_figure *lst);
t_figure	*lstlast_figure(t_figure *lst);
t_figure	*lstadd_figure(char **line, int type);
void		lstclear_figure(t_figure **lst);
void		lstback_figure(t_figure **pars, t_figure *new);

void		mlx_create(t_scene *scene);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

int			mouse(void);
int			close_window(t_scene *scene);
int			button_press(void);
int			mlx_keypress(int keypress, t_scene *scene);

void		ray_tracing(t_scene *scene, int mlx_x, int mlx_y);
void		ray_norm(t_figure *fig, t_vect p);
float		closest_inter(t_vect pos, t_vect ray, t_figure *figure, t_figure **tmp1);
float		sphere_intersection(t_vect pos, t_vect ray, t_sph *sph);
float		plane_inter(t_vect pos, t_vect ray, t_pl *plane);
float		compute_light(float dot, t_scene *scene, t_figure *tmp);
float		compute_spec(t_scene *scene, t_vect light, float	n_dot_l, t_figure *fig);
t_vplane	*get_vplane(float height, float width, float fov);

t_vect		new_vect(float x, float y, float z);
t_vect		substraction_vect(t_vect v1, t_vect v2);
float		length_vect(t_vect vec);
float		dot_product_vect(t_vect v1, t_vect v2);
t_vect		norm_vect(t_vect vector);
t_vect		num_product_vect(t_vect vec, float num);
t_vect		sum_vect(t_vect v1, t_vect v2);

#endif