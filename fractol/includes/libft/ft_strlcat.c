/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:30:09 by srison            #+#    #+#             */
/*   Updated: 2014/11/12 14:22:39 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sizesrc;
	char	*stock;

	sizesrc = ft_strlen(src);
	if (sizesrc > size)
		sizesrc = size;
	stock = dst;
	stock = &(stock[ft_strlen(stock) + 1]);
	if (ft_strlen(stock) >= sizesrc)
	{
		if (ft_strlen(stock) > sizesrc)
			dst[ft_strlen(dst) + sizesrc + 1] = '\0';
		ft_bzero(&(dst[ft_strlen(dst) + 1]), sizesrc);
		ft_strncat(dst, src, sizesrc);
		return (ft_strlen(dst));
	}
	return (0);
}
