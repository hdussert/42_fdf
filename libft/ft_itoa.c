/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 23:25:53 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/29 17:38:05 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		nb;
	int		neg;
	int		c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = (n < 0 ? -n : n);
	c = 1;
	while (nb /= 10)
		c++;
	neg = (n < 0 ? 1 : 0);
	str = (char *)malloc(sizeof(char) * (c + neg + 1));
	if (str == NULL)
		return (NULL);
	str[c + neg] = '\0';
	str += neg;
	n = (n < 0 ? -n : n);
	while (c-- > 0)
	{
		str[c] = n % 10 + '0';
		n /= 10;
	}
	(str -= neg)[0] = (neg ? '-' : str[0]);
	return (str);
}
