/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 04:58:30 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/30 17:33:45 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		neg = (str[i++] == '-' ? -1 : 1);
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48) * neg;
	return (res);
}
