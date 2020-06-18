/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:14:13 by hdussert          #+#    #+#             */
/*   Updated: 2018/05/08 09:15:24 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] == '\n' || str[i] == ' ' || str[i] == '	')
			i++;
		if (str[i])
		{
			cpt++;
			while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '	')
				i++;
		}
	}
	return (cpt);
}

int		count_letters(char *str, int nb)
{
	int i;
	int cpt;
	int letter;

	i = 0;
	cpt = 0;
	letter = 0;
	while (str[i] && cpt < nb)
	{
		while (str[i] == '\n' || str[i] == ' ' || str[i] == '	')
			i++;
		if (str[i])
		{
			cpt++;
			while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '	')
			{
				if (cpt == nb)
					letter++;
				i++;
			}
		}
	}
	return (letter);
}

void	fill(char *str, int nb, char *res)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (str[i] && cpt < nb)
	{
		while (str[i] == '\n' || str[i] == ' ' || str[i] == '	')
			i++;
		if (str[i])
		{
			cpt++;
			while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '	')
			{
				if (cpt == nb)
				{
					res[j] = str[i];
					j++;
				}
				i++;
			}
		}
	}
}

char	**ft_strsplit(char *str)
{
	char	**res;
	int		nb_words;
	int		letters;
	int		i;

	nb_words = count_words(str);
	res = (char **)malloc(sizeof(char *) * nb_words + 1);
	res[nb_words] = NULL;
	i = -1;
	while (++i < nb_words)
	{
		letters = count_letters(str, i + 1);
		res[i] = (char *)malloc(sizeof(char) * letters + 1);
		res[i][letters] = '\0';
		fill(str, i + 1, res[i]);
	}
	return (res);
}
