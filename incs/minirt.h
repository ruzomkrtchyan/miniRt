/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:51:35 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/12/17 17:56:27 by vhovhann         ###   ########.fr       */
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
# include <pthread.h>
# include <fcntl.h>
# include "structs.h"
# include "libft.h"
# include "get_next_line_bonus.h"

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
void		destroy_exit(t_thread *thr);

t_scene		*pars(char **arr, t_scene *scene);
void		check_fname(char *str);
void		check_ident_name(char **arr);
int			check_identifier(char **arr);
int			check_ident_args(char **arr);
int			check_args_amb(char **line);
int			check_args_cam(char **line);
int			check_args_light(char **line);
int			check_args_cone(char **line);
int			check_args_plane(char **line);
int			check_args_sphere(char **line);
int			check_args_cylinder(char **line);

/***********************************************/
/**************LST_UTILS_SPHERE*****************/
/***********************************************/

t_amb		*fill_amb(char **line);
t_cam		*fill_cam(char **line);

t_pl		*init_pl(char **line);
t_cyl		*init_cyl(char **line);
t_sph		*init_sp(char **line);
t_cone		*init_cone(char **line);

t_light		*lstadd_light(char **line);
t_light		*lstlast_light(t_light *lst);
int			lstsize_light(t_light *lst);
void		lstclear_light(t_light **lst);
void		lstback_light(t_light **pars, t_light *new);

int			lstsize_figure(t_figure *lst);
t_figure	*lstlast_figure(t_figure *lst);
t_figure	*lstadd_figure(char **line, int type);
void		lstclear_figure(t_figure **lst);
void		lstback_figure(t_figure **pars, t_figure *new);

void		mlx_create(t_scene *scene);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

void		close_window(t_thread *thr);
int			button_press(void);
int			mlx_keypress(int keypress, t_thread thr[NUM_THREAD]);
void		start_threads(t_thread thr[NUM_THREAD]);

void		*ray_tracing(void *arg);
void		ray_norm(t_figure *fig, t_vect p);
float		closest_inter(t_vect pos, t_vect ray, t_figure *figure, \
														t_figure **tmp1);
float		sphere_intersection(t_vect pos, t_vect ray, t_sph *sph);
float		plane_inter(t_vect pos, t_vect ray, t_vect n_coord, t_vect coord);
float		vect_proj(t_vect pos, t_vect ray, t_cyl *cyl, t_math *math);
float		cyl_inter(t_vect pos, t_vect ray, t_cyl *cyl);
t_vect		cylray_norm(t_math *math, t_vect ray, t_vect pos, t_cyl *cyl);
float		closest_dist(t_cyl *cyl, t_math *m);
t_rgb		n_prod_col(t_rgb c, float n);
t_rgb		add_col(t_rgb c1, t_rgb c2);
t_rgb		prod_col(t_rgb c1, t_rgb c2, float ratio);
t_rgb		compute_light(t_rgb fig_col, t_light *light, float n_dot_l);
t_rgb		compute_spec(t_scene *scene, t_vect light, t_figure *fig, \
				t_light *lights);
int			compute_shadow(float dot, t_scene *sc, t_figure *tmp, \
				t_light *lights);
t_vplane	*get_vplane(float height, float width, float fov);

t_vect		new_vect(float x, float y, float z);
t_vect		substract_v(t_vect v1, t_vect v2);
float		length_vect(t_vect vec);
float		dot_product_vect(t_vect v1, t_vect v2);
t_vect		norm_vect(t_vect vector);
t_vect		num_product_vect(t_vect vec, float num);
t_vect		sum_vect(t_vect v1, t_vect v2);
float		dist_vect(t_vect v1, t_vect v2);

t_matrix	matrix_sum(t_matrix m1, t_matrix m2);
t_matrix	new_zero_matrix(void);
t_vect		multi_mat_vect(t_matrix m, t_vect v);
t_matrix	matrix_mult(t_matrix m1, t_matrix m2);
t_matrix	scale_matrix(int sx, int sy, int sz);
t_matrix	move_matrix(int dx, int dy, int dz);

void		move_right(t_scene *scene);
void		move_left(t_scene *scene);;
t_matrix	get_rotation_z(float angle);
t_matrix	get_rotation_y(float angle);
t_matrix	get_rotation_x(float angle);

void		_move_(int keypress, t_scene *scene);
void		_rotate_(int keypress, t_scene *scene);

void		rotate_scene_up(t_scene *scene);
void		rotate_scene_left(t_scene *scene);
void		rotate_scene_right(t_scene *scene);
void		rotate_scene_down(t_scene *scene);

void		rotate_sphere(t_sph *sph, t_matrix matrix);
void		rotate_light(t_light **light, t_matrix matrix);
void		rotate_plane(t_pl *plane, t_matrix matrix);
void		rotate_cylinder(t_cyl *cylinder, t_matrix matrix);

#endif