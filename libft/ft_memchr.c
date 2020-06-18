/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:13:01 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/29 19:29:56 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte *str;

	str = (t_byte *)s;
	while (n--)
	{
		if (*str == (t_byte)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
