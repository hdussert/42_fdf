/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:54:58 by hdussert          #+#    #+#             */
/*   Updated: 2017/11/29 16:22:33 by hdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst && *f)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return (NULL);
		new = f(lst);
		if (lst->next != NULL)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
