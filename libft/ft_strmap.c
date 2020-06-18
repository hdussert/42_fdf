/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:26 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 11:41:43 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	if (s && f)
	{
		dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (dst == NULL)
			return (NULL);
		i = -1;
		while (s[++i])
			dst[i] = f(s[i]);
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
