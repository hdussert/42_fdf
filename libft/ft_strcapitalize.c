/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:49:55 by hdussert          #+#    #+#             */
/*   Updated: 2017/12/05 16:50:42 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str && str[++i])
	{
		if (i == 0 || str[i - 1] < '0' || (str[i - 1] > '9' && str[i - 1] < 'A')
			|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || str[i - 1] > 'z')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
		}
	}
	return (str);
}
