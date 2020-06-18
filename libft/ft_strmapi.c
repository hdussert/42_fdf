/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:40:36 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/28 11:40:38 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dst[i] = f(i, s[i]);
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
