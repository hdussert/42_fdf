/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:31:40 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 10:10:38 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			set_color(double z)
{
	double		r;
	double		g;
	double		b;
	int			res;

	r = sin(0.15 * z) * 127 + 128;
	g = sin(0.15 * z + (M_PI / 3) * 2) * 127 + 128;
	b = sin(0.15 * z + (M_PI / 3) * 4) * 127 + 128;
	res = (int)(r) << 16;
	res += (int)(g) << 8;
	res += (int)(b);
	return (res);
}

static t_pixel		*init_pix(double z)
{
	t_pixel		*pixel;

	if (!(pixel = (t_pixel *)malloc(sizeof(t_pixel))))
		exit(1);
	pixel->c = set_color(z * 90);
	return (pixel);
}

t_map_r				*new_map_r(t_map *map)
{
	t_map_r		*map_r;
	int			i;
	int			j;

	if (!(map_r = (t_map_r *)malloc(sizeof(t_map_r)))
	|| !(map_r->m = (t_pixel ***)malloc(sizeof(t_pixel **) * map->row)))
		exit(1);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		if (!(map_r->m[i] = (t_pixel **)malloc(sizeof(t_pixel *) * map->col)))
			exit(1);
		while (++j < map->col)
			map_r->m[i][j] = init_pix(map->m[i][j]->z);
	}
	return (map_r);
}
