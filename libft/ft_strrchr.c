/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 05:33:17 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/25 05:38:57 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int indice;

	i = -1;
	indice = -1;
	while (s[++i])
		if (s[i] == (char)c)
			indice = i;
	if (indice >= 0)
		return ((char *)(s + indice));
	else if (c == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}
