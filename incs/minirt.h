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
# include "get_next_line_bonus.h"

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef	struct s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef	struct s_light
{
	t_coord	*cord;
	t_rgb	*color;
	double	bright;
}				t_light;

typedef	struct s_sph
{
	t_coord	*cord;
	t_rgb	*color;
	double	diam;
}				t_sph;

typedef	struct s_pl
{
	t_coord	*cord;
	t_coord	*n_cord;
	t_rgb	*color;
}				t_pl;

typedef	struct s_cyl
{
	t_coord	*cord;
	t_coord	*n_cord;
	t_rgb	*color;
	double	diam;
	double	height;
}				t_cyl;

typedef	struct s_amb
{
	double	ratio;
	t_rgb	*color;
}				t_amb;

typedef struct s_cam
{
	t_coord	*dir;
	t_coord	*pos;
	double	degree;
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
	t_rgb	*color;
}				t_pars;

/*************************************/
/**************UTILS******************/
/*************************************/

char	*ft_strjoin(char *s1, char *s2, int flag);
char	*ft_strnstr(char *s1, char *s2, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strrchr( char *str, int c);
char	*ft_strrchr( char *str, int c);
char	*ft_strchr( char *str, int c);
char	**ft_split_2(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

void	check_fname(char *str);
char	*read_file(char *str);

#endif