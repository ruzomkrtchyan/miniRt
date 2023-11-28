/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:28:29 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/28 12:45:00 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_figure_type
{
	CYLINDER,
	SPHERE,
	PLANE,
}				t_type;

typedef struct s_matrix
{
	float	m[4][4];
}				t_matrix;


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	height;
	float	width;
}				t_data;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_math
{
	float	a;
	float	b;
	float	c;
	float	disc;
	float	x1;
	float	x2;
}				t_math;

typedef struct s_vect
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vect;

typedef struct s_light
{
	t_vect	coord;
	t_rgb	*color;
	float	bright;
}				t_light;

typedef struct s_sph
{
	float			radius;
	float			spec;
	float			dist;
	t_vect			coord;
	t_rgb			*color;
}				t_sph;

typedef struct s_pl
{
	t_vect		coord;
	float		spec;
	t_vect		n_coord;
	t_rgb		*color;
}				t_pl;

typedef struct s_cyl
{
	t_vect		coord;
	t_vect		n_coord;
	t_rgb		*color;
	float		spec;
	float		radius;
	float		height;
}			t_cyl;

typedef struct s_amb
{
	float	ratio;
	t_rgb	*color;
}				t_amb;

typedef struct s_cam
{
	t_vect	dir;
	t_vect	pos;
	float	fov;
}				t_cam;

typedef struct s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

typedef struct s_figure
{
	t_sph			*sph;
	t_pl			*pl;
	t_cyl			*cyl;
	t_type			type;
	t_rgb			*color;
	float			spec;
	t_vect			ray_norm;
	struct s_figure	*next;
}				t_figure;

typedef struct s_scene
{
	t_amb		*amb;
	t_light		*light;
	t_cam		*cam;
	t_figure	*figure;
	t_data		*data;
	t_mlx		*mlx;
	t_vplane	*vplane;
	t_vect		ray;
	float		height;
	float		width;
}				t_scene;

#endif