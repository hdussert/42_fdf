/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:13:47 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/09 16:28:54 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		calc_gradient(int color1, int color2, double stage)
{
	int		color;
	int		r;
	int		g;
	int		b;

	r = (int)(((color1 >> 16) & 0xFF) +
			(((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF)) * stage) << 16;
	g = (int)(((color1 >> 8) & 0xFF) +
			(((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF)) * stage) << 8;
	b = (int)((color1 & 0xFF) +
			((color2 & 0xFF) - (color1 & 0xFF)) * stage);
	color = (125 << 24) | r | g | b;
	return (color);
}
