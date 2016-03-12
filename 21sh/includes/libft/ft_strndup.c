/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:35:24 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 14:31:59 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	char	*dst;
	size_t	size;
	size_t	index;

	index = 0;
	size = n;
	if (size > ft_strlen(s1))
		size = ft_strlen(s1);
	dst = ft_strnew(size);
	while (index < size)
	{
		dst[index] = s1[index];
		index++;
	}
	return (dst);
}
