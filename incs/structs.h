/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:28:29 by vhovhann          #+#    #+#             */
/*   Updated: 2023/11/06 20:09:06 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_data
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

typedef struct s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef struct s_light
{
	t_vect	*coord;
	t_rgb	*color;
	float	bright;
}				t_light;

typedef struct s_sph
{
	float			radius;
	float			spec;
	float			dist;
	t_vect			*coord;
	t_rgb			*color;
	struct s_sph	*next;
}				t_sph;

typedef struct s_pl
{
	t_vect		*coord;
	t_vect		*n_coord;
	t_rgb		*color;
	struct s_pl	*next;
}				t_pl;

typedef struct s_cyl
{
	t_vect			*coord;
	t_vect			*n_coord;
	t_rgb			*color;
	float			diam;
	float			height;
	struct s_cyl	*next;
}				t_cyl;

typedef struct s_amb
{
	float	ratio;
	t_rgb	*color;
}				t_amb;

typedef struct s_cam
{
	t_vect	*dir;
	t_vect	*pos;
	float	fov;
}				t_cam;

typedef struct s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

typedef struct s_scene
{
	t_amb	*amb;
	t_light	*light;
	t_sph	*sph;
	t_pl	*pl;
	t_cyl	*cyl;
	t_cam	*cam;
	t_data	*data;
	t_mlx	*mlx;
	float	height;
	float	width;
}				t_scene;

#endif