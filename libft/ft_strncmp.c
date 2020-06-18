/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 04:51:22 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 17:56:02 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i] && (size_t)i < n)
		;
	if ((size_t)i == n)
		return ((int)((unsigned char)(s1[i - 1]) - (unsigned char)(s2[i - 1])));
	return ((int)((unsigned char)(s1[i]) - (unsigned char)(s2[i])));
}
