/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:22:26 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 11:44:13 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	int		i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size >= dlen)
	{
		if (size - dlen > 1)
		{
			i = -1;
			while ((size_t)++i < size - dlen - 1 && src[i])
				dst[dlen + i] = src[i];
			dst[dlen + i] = '\0';
		}
		return (dlen + slen);
	}
	return (slen + size);
}
