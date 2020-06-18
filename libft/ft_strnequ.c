/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:11 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/30 16:00:37 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if ((!s1 && !s2) || !n)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i] && (size_t)i < n)
		if (s1[i] != s2[i])
			return (0);
	if (s2[i] && (size_t)i < n)
		return (0);
	return (1);
}
