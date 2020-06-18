/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:14:57 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 17:37:16 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*test1;
	unsigned char	*test2;

	test1 = (unsigned char *)s1;
	test2 = (unsigned char *)s2;
	while (n > 0 && *test1 == *test2)
	{
		n--;
		test1++;
		test2++;
	}
	if (n == 0)
		return (0);
	return (*test1 - *test2);
}
