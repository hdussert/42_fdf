/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:32:03 by hdussert          #+#    #+#             */
/*   Updated: 2018/08/16 00:32:43 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_pos
{
	int			x;
	int			y;
}					t_pos;

typedef struct		s_vec2
{
	double		x;
	double		y;
}					t_vec2;

typedef struct		s_line
{
	t_vec2		cur;
	t_vec2		dir;
	t_pos		inc;
	double		inc_color;
	int			cur_color;
}					t_line;

typedef struct		s_pixel
{
	double		x;
	double		y;
	double		z;
	int			c;
}					t_pixel;

typedef struct		s_matrix
{
	double		m[3][3];
}					t_matrix;

typedef struct		s_vec3
{
	double		x;
	double		y;
	double		z;
}					t_vec3;

typedef struct		s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			q;
	int			e;
	int			add;
	int			sub;
}					t_keys;

typedef struct		s_cam
{
	t_vec3		*angles;
	t_matrix	*rot_x;
	t_matrix	*rot_y;
	t_matrix	*rot_z;
	t_matrix	*rot_m;

	double		z_offset;
	double		inc;
}					t_cam;

typedef struct		s_map_r
{
	t_pixel		***m;
}					t_map_r;

typedef struct		s_map
{
	int			col;
	int			row;
	int			h_max;
	int			h_min;
	t_vec3		***m;
}					t_map;

typedef struct		s_image
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			s_l;
	int			endian;
}					t_image;

typedef struct		s_fdf
{
	int			size;
	double		size_2;
	int			fd[2];
	void		*mlx;
	void		*window;
	t_image		*image;
	int			time;

	t_map		*map;
	t_map_r		*map_r;

	t_cam		*cam;
	t_keys		*keys;
}					t_fdf;

t_fdf				*new_fdf(char *name, unsigned int size, char *file);

int					calc_gradient(int color1, int color2, double stage);
t_vec3				*new_vec3(double x, double y, double z);
void				vec_to_pixel(t_vec3 *v, t_pixel *p, t_fdf *fdf);

t_matrix			*new_matrix(void);
void				calc_rot_m(t_cam *cam);

int					key_down(int key, t_fdf *fdf);
int					key_up(int key, t_fdf *fdf);
int					loop(t_fdf *fdf);
t_map				*new_map(t_fdf *fdf);
t_map_r				*new_map_r(t_map *map);

void				draw(t_fdf *fdf);
#endif
