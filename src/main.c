/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:46:39 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/18 09:13:28 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = new_fdf("FDF", 800, argv[1]);
		mlx_hook(fdf->window, 2, 0, key_down, fdf);
		mlx_hook(fdf->window, 3, 0, key_up, fdf);
		mlx_loop_hook(fdf->mlx, loop, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
