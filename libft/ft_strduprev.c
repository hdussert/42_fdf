/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduprev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:36:06 by hdussert          #+#    #+#             */
/*   Updated: 2017/12/05 16:13:57 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strduprev(char *str)
{
	char	*s;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		s[len - i - 1] = str[i];
	s[len] = '\0';
	return (s);
}
