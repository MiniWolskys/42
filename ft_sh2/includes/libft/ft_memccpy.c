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
	size_t			i;
	unsigned char	*destchar;
	unsigned char	*srcchar;

	if (dst == NULL || src == NULL || (int)n < 0)
		return (NULL);
	destchar = (unsigned char*)dst;
	srcchar = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		if (srcchar[i] == (unsigned char)c)
		{
			destchar[i] = srcchar[i];
			return (&(destchar[i + 1]));
		}
		destchar[i] = srcchar[i];
		++i;
	}
	return (NULL);
}
