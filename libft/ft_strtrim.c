/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:37:09 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/29 11:20:06 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int len;

	if (s)
	{
		len = ft_strlen(s);
		i = -1;
		j = len;
		while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
			;
		while ((s[--j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
			;
		j = len - j - 1;
		return (ft_strsub(s, i, len - j - i));
	}
	return (0);
}
