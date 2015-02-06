/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:29:09 by srison            #+#    #+#             */
/*   Updated: 2014/11/21 15:47:40 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;
	char		*str;

	str = (char *)s;
	index = 0;
	while (index < n && str[index])
	{
		if (str[index] == (char)c)
			return (&str[index]);
		index++;
	}
	return (NULL);
}
