/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:57:12 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 09:51:11 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_down(int key, t_fdf *fdf)
{
	if (key == 12)
		fdf->keys->q = 1;
	else if (key == 13)
		fdf->keys->w = 1;
	else if (key == 14)
		fdf->keys->e = 1;
	else if (key == 0)
		fdf->keys->a = 1;
	else if (key == 1)
		fdf->keys->s = 1;
	else if (key == 2)
		fdf->keys->d = 1;
	else if (key == 69)
		fdf->keys->add = 1;
	else if (key == 78)
		fdf->keys->sub = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int		key_up(int key, t_fdf *fdf)
{
	if (key == 12)
		fdf->keys->q = 0;
	else if (key == 13)
		fdf->keys->w = 0;
	else if (key == 14)
		fdf->keys->e = 0;
	else if (key == 0)
		fdf->keys->a = 0;
	else if (key == 1)
		fdf->keys->s = 0;
	else if (key == 2)
		fdf->keys->d = 0;
	else if (key == 69)
		fdf->keys->add = 0;
	else if (key == 78)
		fdf->keys->sub = 0;
	return (0);
}

int		loop(t_fdf *fdf)
{
	if (fdf->keys->q == 1)
		fdf->cam->angles->z += fdf->cam->inc;
	else if (fdf->keys->e == 1)
		fdf->cam->angles->z -= fdf->cam->inc;
	if (fdf->keys->w == 1)
		fdf->cam->angles->x += fdf->cam->inc;
	else if (fdf->keys->s == 1)
		fdf->cam->angles->x -= fdf->cam->inc;
	if (fdf->keys->a == 1)
		fdf->cam->angles->y += fdf->cam->inc;
	else if (fdf->keys->d == 1)
		fdf->cam->angles->y -= fdf->cam->inc;
	if (fdf->keys->add == 1)
		fdf->cam->z_offset += fdf->cam->inc;
	else if (fdf->keys->sub == 1 && fdf->cam->z_offset - fdf->cam->inc > 0.5)
		fdf->cam->z_offset -= fdf->cam->inc;
	fdf->time %= 200;
	if (++fdf->time == 1)
		draw(fdf);
	return (0);
}
