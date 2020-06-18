/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:45:55 by hdussert          #+#    #+#             */
/*   Updated: 2018/08/13 02:10:23 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_addlist(int fd, t_lstgnl **first, t_lstgnl *temp, t_lstgnl *last)
{
	if (temp)
	{
		if (!*first)
		{
			*first = temp;
			(*first)->next = NULL;
		}
		else
		{
			temp->next = *first;
			*first = temp;
		}
	}
	else
	{
		temp = *first;
		while (temp->fd != fd && (last = temp))
			temp = temp->next;
		if (temp == *first)
			*first = (*first)->next;
		else
			last->next = temp->next;
		free(temp);
	}
}

static int	ft_initbuff(int fd, t_lstgnl **first, char **buff)
{
	int			ret;
	t_lstgnl	*temp;

	temp = *first;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
	{
		if (!(temp = (t_lstgnl *)malloc(sizeof(*temp))))
			return (-1);
		ft_addlist(fd, first, temp, NULL);
		ft_bzero(temp->buff, BUFF_SIZE + 1);
		temp->fd = fd;
	}
	*buff = temp->buff;
	if (!ft_strlen(*buff))
	{
		if ((ret = read(fd, *buff, BUFF_SIZE)) < 0)
			return (-1);
	}
	else
		ret = 1;
	return (ret);
}

static int	ft_splitendline(char *buff, char **new)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < BUFF_SIZE && buff[i] != 0 && buff[i] != '\n')
		i++;
	if (i == BUFF_SIZE || (buff[i] != '\n' && i != 0))
		ret = 1;
	if (!(*new = ft_strnew(i)))
		return (-1);
	if (!(ft_strncpy(*new, buff, i)))
		return (-1);
	if (ret)
		ft_bzero(buff, BUFF_SIZE + 1);
	else if (!(ft_strncpy(buff, buff + i + 1, BUFF_SIZE)))
		return (-1);
	return (ret);
}

static int	ft_createlinefull(char **full, char **new)
{
	char	*temp;

	temp = NULL;
	if (!*new)
		return (-1);
	else if (!*full)
	{
		*full = *new;
		*new = NULL;
	}
	else
	{
		if (!(temp = ft_strjoin(*full, *new)))
			return (-1);
		free(*new);
		*new = NULL;
		free(*full);
		*full = temp;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_lstgnl	*first = NULL;
	char			*buff;
	char			*new;
	int				ret;
	int				next;

	buff = NULL;
	new = NULL;
	ret = 0;
	next = 1;
	if (fd < 0 || !line || !BUFF_SIZE)
		return (-1);
	*line = NULL;
	while (next)
	{
		if ((ret = ft_initbuff(fd, &first, &buff)) < 0 ||
				(next = ft_splitendline(buff, &new)) < 0 ||
				(ft_createlinefull(line, &new)) < 0)
			return (-1);
	}
	if (ft_strlen(*line) || ft_strlen(buff) || ret)
		return (1);
	ft_addlist(fd, &first, NULL, first);
	return (0);
}
