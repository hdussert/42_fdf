/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:44:52 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/30 15:59:51 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i])
		if (s1[i] != s2[i])
			return (0);
	if (s2[i])
		return (0);
	return (1);
}
