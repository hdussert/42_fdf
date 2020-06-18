/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 04:30:02 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 17:49:45 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && (size_t)i < len)
		if (haystack[i] == needle[0])
		{
			j = -1;
			while (needle[++j] && needle[j] == haystack[i + j]
					&& (size_t)(i + j) < len)
				;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
	return (NULL);
}
