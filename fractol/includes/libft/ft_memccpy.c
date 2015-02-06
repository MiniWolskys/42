/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:42:47 by srison            #+#    #+#             */
/*   Updated: 2014/11/09 14:18:03 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		index;
	char		*dest;
	char		*str;

	dest = (char *)dst;
	str = (char *)src;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (&str[index + 1]);
		if (index < n)
			dest[index] = str[index];
		index++;
	}
	return (NULL);
}
