/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:43:56 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 10:27:43 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix				*new_matrix(void)
{
	t_matrix	*m;
	int			i;
	int			j;

	if (!(m = (t_matrix *)malloc(sizeof(t_matrix))))
		exit(1);
	j = -1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
			m->m[j][i] = 0;
	}
	return (m);
}

t_vec3					*new_vec3(double x, double y, double z)
{
	t_vec3		*vec;

	if (!(vec = (t_vec3 *)malloc(sizeof(t_vec3))))
		exit(1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

static inline void		mult_vecmat_to_pix(t_vec3 *v, t_matrix *m, t_pixel *p)
{
	p->x = v->x * m->m[0][0] + v->y * m->m[1][0] + v->z * m->m[2][0];
	p->y = v->x * m->m[0][1] + v->y * m->m[1][1] + v->z * m->m[2][1];
	p->z = v->x * m->m[0][2] + v->y * m->m[1][2] + v->z * m->m[2][2];
	v->x = p->x;
	v->y = p->y;
	v->z = p->z;
}

void					vec_to_pixel(t_vec3 *v, t_pixel *pix, t_fdf *fdf)
{
	mult_vecmat_to_pix(v, fdf->cam->rot_m, pix);
	fdf->cam->angles->x = 0;
	fdf->cam->angles->y = 0;
	fdf->cam->angles->z = 0;
	pix->z = -pix->z;
	pix->z += fdf->cam->z_offset;
	pix->x = (1 - pix->x / pix->z) * fdf->size_2;
	pix->y = (1 - pix->y / pix->z) * fdf->size_2;
}
