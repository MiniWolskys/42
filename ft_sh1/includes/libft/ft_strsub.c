/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:49:44 by srison            #+#    #+#             */
/*   Updated: 2014/11/07 21:05:05 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*dest;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(dest = ft_strnew(len + 1)))
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		dest[index] = s[start + index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
