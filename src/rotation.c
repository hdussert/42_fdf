/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:54:20 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 10:52:33 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void		set_rot_x(t_matrix *m, double angle)
{
	m->m[0][0] = 1.0;
	m->m[1][1] = cos(angle);
	m->m[1][2] = -sin(angle);
	m->m[2][1] = sin(angle);
	m->m[2][2] = cos(angle);
}

static inline void		set_rot_y(t_matrix *m, double angle)
{
	m->m[0][0] = cos(angle);
	m->m[0][2] = sin(angle);
	m->m[1][1] = 1.0;
	m->m[2][0] = -sin(angle);
	m->m[2][2] = cos(angle);
}

static inline void		set_rot_z(t_matrix *m, double angle)
{
	m->m[0][0] = cos(angle);
	m->m[0][1] = -sin(angle);
	m->m[1][0] = sin(angle);
	m->m[1][1] = cos(angle);
	m->m[2][2] = 1.0;
}

static inline void		mult_matrix(t_matrix *m1, t_matrix *m2, t_matrix *m_r)
{
	int		i;
	int		j;
	int		k;
	double	sum;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			sum = 0;
			k = -1;
			while (++k < 3)
				sum += (m1->m[i][k] * m2->m[k][j]);
			m_r->m[i][j] = sum;
		}
	}
}

void					calc_rot_m(t_cam *cam)
{
	t_matrix	*tmp;

	if (!(tmp = (t_matrix *)malloc(sizeof(t_matrix))))
		exit(1);
	else
	{
		cam->angles->x -= (cam->angles->x > M_PI * 2 ? M_PI * 2 : 0);
		cam->angles->x += (cam->angles->x < -(M_PI * 2) ? M_PI * 2 : 0);
		cam->angles->y -= (cam->angles->y > M_PI * 2 ? M_PI * 2 : 0);
		cam->angles->y += (cam->angles->y < -(M_PI * 2) ? M_PI * 2 : 0);
		cam->angles->z -= (cam->angles->z > M_PI * 2 ? M_PI * 2 : 0);
		cam->angles->z += (cam->angles->z < -(M_PI * 2) ? M_PI * 2 : 0);
		set_rot_x(cam->rot_x, cam->angles->x);
		set_rot_y(cam->rot_y, cam->angles->y);
		set_rot_z(cam->rot_z, cam->angles->z);
		mult_matrix(cam->rot_y, cam->rot_x, tmp);
		mult_matrix(cam->rot_z, tmp, cam->rot_m);
		free(tmp);
	}
}
