/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:13:25 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 11:53:16 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < fdf->size && y < fdf->size)
		((unsigned int *)fdf->image->ptr)[x + y * fdf->size] = color;
}

static void			dx_dom(t_line *l, t_fdf *fdf, t_pixel *start, t_pixel *end)
{
	double		stack;
	int			i;
	double		percent;

	percent = 0;
	stack = l->dir.x / 2.0;
	i = 0;
	while (++i <= l->dir.x)
	{
		percent += l->inc_color;
		l->cur.x += l->inc.x;
		stack += l->dir.y;
		if (stack >= l->dir.x)
		{
			stack -= l->dir.x;
			l->cur.y += l->inc.y;
		}
		if ((l->inc.x > 0 && l->cur.x >= fdf->size)
		|| (l->inc.x < 0 && l->cur.x < 0) || (l->inc.y < 0 && l->cur.y < 0)
		|| (l->inc.y > 0 && l->cur.y >= fdf->size))
			break ;
		my_pixel_put(fdf, round(l->cur.x), round(l->cur.y),
					calc_gradient(start->c, end->c, percent));
	}
}

static void			dy_dom(t_line *l, t_fdf *fdf, t_pixel *start, t_pixel *end)
{
	double		stack;
	int			i;
	double		percent;

	percent = 0;
	stack = l->dir.y / 2.0;
	i = 0;
	while (++i <= l->dir.y)
	{
		percent += l->inc_color;
		l->cur.y += l->inc.y;
		stack += l->dir.x;
		if (stack >= l->dir.y)
		{
			stack -= l->dir.y;
			l->cur.x += l->inc.x;
		}
		if ((l->inc.x > 0 && l->cur.x >= fdf->size)
		|| (l->inc.x < 0 && l->cur.x < 0) || (l->inc.y < 0 && l->cur.y < 0)
		|| (l->inc.y > 0 && l->cur.y >= fdf->size))
			break ;
		my_pixel_put(fdf, round(l->cur.x), round(l->cur.y),
					calc_gradient(start->c, end->c, percent));
	}
}

static void			line(t_fdf *fdf, t_pixel *start, t_pixel *end)
{
	t_line *l;

	if (!(l = (t_line *)malloc(sizeof(t_line))))
		exit(1);
	if (start->z > 0 && end->z > 0 && (((start->x >= 0 && start->x <= fdf->size)
	&& (start->y >= 0 && start->y <= fdf->size)) || ((end->x >= 0 &&
	end->x <= fdf->size) && (end->y >= 0 && end->y <= fdf->size))))
	{
		my_pixel_put(fdf, round(start->x), round(start->y), start->c);
		my_pixel_put(fdf, round(end->x), round(end->y), end->c);
		l->cur.x = start->x;
		l->cur.y = start->y;
		l->dir.x = end->x - start->x;
		l->dir.y = end->y - start->y;
		l->inc.x = (l->dir.x > 0) ? 1 : -1;
		l->inc.y = (l->dir.y > 0) ? 1 : -1;
		l->dir.x = fabs(l->dir.x);
		l->dir.y = fabs(l->dir.y);
		l->inc_color = (l->dir.x > l->dir.y ? 1.0 / l->dir.x : 1.0 / l->dir.y);
		if (l->dir.x > l->dir.y)
			dx_dom(l, fdf, start, end);
		else
			dy_dom(l, fdf, start, end);
	}
	free(l);
}

void				draw(t_fdf *fdf)
{
	int		i;
	int		j;

	ft_bzero((int *)fdf->image->ptr, fdf->size * fdf->size * 4);
	calc_rot_m(fdf->cam);
	i = fdf->map->row;
	if (fdf->map->col == 1 && fdf->map->row == 1)
		my_pixel_put(fdf, fdf->map_r->m[0][0]->x, fdf->map_r->m[0][0]->y,
			fdf->map_r->m[0][0]->c);
	while (--i >= 0)
	{
		j = fdf->map->col;
		while (--j >= 0)
		{
			vec_to_pixel(fdf->map->m[i][j], fdf->map_r->m[i][j], fdf);
			if (j + 1 < fdf->map->col)
				line(fdf, fdf->map_r->m[i][j], fdf->map_r->m[i][j + 1]);
			if (i + 1 < fdf->map->row)
				line(fdf, fdf->map_r->m[i][j], fdf->map_r->m[i + 1][j]);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image->img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->window, 20, 20, 0xFFFFFF,
			"Rotate: x: w/s | y: a/d | z: q/e");
	mlx_string_put(fdf->mlx, fdf->window, 20, 40, 0xFFFFFF, "Zoom: +/-");
}
