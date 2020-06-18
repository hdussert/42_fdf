/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 10:30:16 by hdussert          #+#    #+#             */
/*   Updated: 2018/08/15 23:55:26 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cam	*new_cam(void)
{
	t_cam		*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		exit(1);
	if (!(cam->angles = new_vec3(0, 0, 0))
	|| !(cam->rot_x = new_matrix())
	|| !(cam->rot_y = new_matrix())
	|| !(cam->rot_z = new_matrix())
	|| !(cam->rot_m = new_matrix()))
		exit(1);
	cam->z_offset = 2;
	cam->inc = M_PI / 10000.0;
	return (cam);
}

static t_keys	*new_keys(void)
{
	t_keys		*keys;

	if (!(keys = (t_keys *)malloc(sizeof(t_keys))))
		exit(1);
	keys->q = 0;
	keys->w = 0;
	keys->e = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->add = 0;
	keys->sub = 0;
	return (keys);
}

static t_image	*new_image(t_fdf *fdf)
{
	t_image		*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		exit(1);
	if (!(img->img = mlx_new_image(fdf->mlx, fdf->size, fdf->size)))
		exit(1);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->s_l, &img->endian);
	return (img);
}

t_fdf			*new_fdf(char *name, unsigned int size, char *file)
{
	t_fdf		*fdf;
	char		tmp[2];

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		exit(1);
	fdf->size = size;
	fdf->size_2 = size / 2.0;
	fdf->time = 0;
	if ((fdf->fd[0] = open(file, O_RDONLY)) < 2
	|| read(fdf->fd[0], tmp, 0) < 0
	|| (fdf->fd[1] = open(file, O_RDONLY)) < 2
	|| !(fdf->mlx = mlx_init())
	|| !(fdf->window = mlx_new_window(fdf->mlx, fdf->size, fdf->size, name))
	|| !(fdf->image = new_image(fdf))
	|| !(fdf->keys = new_keys())
	|| !(fdf->map = new_map(fdf))
	|| !(fdf->map_r = new_map_r(fdf->map))
	|| !(fdf->cam = new_cam()))
		exit(1);
	return (fdf);
}
