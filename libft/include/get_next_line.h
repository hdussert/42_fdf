/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:47:05 by hdussert          #+#    #+#             */
/*   Updated: 2018/08/13 00:41:03 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000

# include "../libft.h"

typedef struct			s_lstgnl
{
	int					fd;
	char				buff[BUFF_SIZE + 1];
	struct s_lstgnl		*next;
}						t_lstgnl;

int						get_next_line(const int fd, char **line);

#endif
