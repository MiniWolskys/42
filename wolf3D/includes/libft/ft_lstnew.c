/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sltnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:07:56 by srison            #+#    #+#             */
/*   Updated: 2014/11/21 07:12:37 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(content))
		content_size = 0;
	list = (t_list *)malloc(sizeof(t_list));
	if (!(list))
		return (NULL);
	list->next = NULL;
	list->content_size = content_size;
	if (content)
	{
		list->content = (void *)malloc(content_size);
		list->content = ft_memcpy(list->content, content, content_size);
	}
	else
		list->content = NULL;
	return (list);
}
