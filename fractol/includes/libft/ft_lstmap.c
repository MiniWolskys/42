/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 05:06:56 by srison            #+#    #+#             */
/*   Updated: 2014/11/21 07:17:52 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	list = ft_lstnew(NULL, 0);
	if (!(list))
		return (NULL);
	while (lst)
	{
		list->next = (t_list *)malloc(sizeof(*list));
		list->next = f(lst);
		if (!(lst->next))
			break;
		list = list->next;
		lst = lst->next;
	}
	return (list);
}
