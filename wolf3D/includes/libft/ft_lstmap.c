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

	if (!(list = ft_memalloc(sizeof(*list))))
		return (NULL);
	list = f(lst);
	if (lst->next)
		list->next = ft_lstmap(lst->next, f);
	return (list);
}
