/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:36:38 by srison            #+#    #+#             */
/*   Updated: 2014/11/21 07:18:01 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*result;
	char		*base;
	size_t		index;

	index = 0;
	base = (char *)src;
	result = (char *)dst;
	while (index < n && base[index])
	{
		result[index] = base[index];
		index++;
	}
	return (dst);
}
