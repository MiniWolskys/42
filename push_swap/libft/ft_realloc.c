/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 15:11:56 by srison            #+#    #+#             */
/*   Updated: 2015/01/01 17:18:57 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **p, size_t size, size_t new_size)
{
	void	*new;

	if (!new_size)
	{
		ft_memdel(p);
		return (NULL);
	}
	if (!(new = ft_memalloc(new_size)))
		return (NULL);
	ft_memcpy(new, *p, (new_size > size) ? size : new_size);
	free(*p);
	return ((*p = new));
}
