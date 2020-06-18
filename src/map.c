/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:12:41 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/08 10:41:04 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	z_calc(int h, double hmin, double hmax)
{
	if (hmin != hmax)
		return ((h - hmin) / (hmax - hmin) * 0.4 - 0.2);
	else
		return (0);
}

static void		init_vec(t_map *map, t_pos pos, int z)
{
	double		trans;

	trans = fmax((map->col + 1) / 2.0, (map->row + 1) / 2.0);
	map->m[pos.y][pos.x] = new_vec3(
							(((map->col - 1) / 2.0) - (double)pos.x) / trans,
							(((map->row - 1) / 2.0) - (double)pos.y) / trans,
							z_calc(z, map->h_min, map->h_max));
}

static void		init_map(t_map *map, int fd, char *line, char **splited_line)
{
	t_pos		cur;

	if (!(map->m = (t_vec3 ***)malloc(sizeof(t_vec3 **) * map->row)))
		exit(1);
	cur.y = 0;
	while (get_next_line(fd, &line))
	{
		if (!(map->m[cur.y] = (t_vec3 **)malloc(sizeof(t_vec3 *) * map->col)))
			exit(1);
		splited_line = ft_strsplit(line, ' ');
		cur.x = -1;
		while (splited_line[++cur.x] != '\0')
			init_vec(map, cur, ft_atoi(splited_line[cur.x]));
		cur.x--;
		while (++cur.x < map->col)
			init_vec(map, cur, 0);
		cur.y++;
		cur.x = -1;
		while (splited_line[++cur.x])
			free(splited_line[cur.x]);
		free(splited_line);
		free(line);
	}
	close(fd);
}

static void		set_dim(t_map *map, int fd, char *line, char **splited_line)
{
	int		len;
	int		cur_h;
	int		i;

	while (get_next_line(fd, &line))
	{
		map->row++;
		splited_line = ft_strsplit(line, ' ');
		map->h_min = (map->row == 1 ? ft_atoi(splited_line[0]) : map->h_min);
		map->h_max = (map->row == 1 ? ft_atoi(splited_line[0]) : map->h_max);
		len = -1;
		while (splited_line[++len] != '\0')
		{
			cur_h = ft_atoi(splited_line[len]);
			map->h_min = (cur_h < map->h_min ? cur_h : map->h_min);
			map->h_max = (cur_h > map->h_max ? cur_h : map->h_max);
		}
		map->col = (len > map->col) ? len : map->col;
		i = -1;
		while (splited_line[++i])
			free(splited_line[i]);
		free(splited_line);
		free(line);
	}
	close(fd);
}

t_map			*new_map(t_fdf *fdf)
{
	t_map		*map;
	char		*line;
	char		**splited_line;

	line = NULL;
	splited_line = NULL;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	map->col = 0;
	map->row = 0;
	set_dim(map, fdf->fd[0], line, splited_line);
	init_map(map, fdf->fd[1], line, splited_line);
	return (map);
}
