/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 04:12:03 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 17:48:13 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = -1;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[++i])
	{
		if (haystack[i] == needle[0])
		{
			j = -1;
			while (needle[++j] && needle[j] == haystack[i + j])
				;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
