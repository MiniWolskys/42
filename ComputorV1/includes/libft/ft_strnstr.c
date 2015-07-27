/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:22:32 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 16:42:21 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i1;
	size_t	i2;

	if (n == 0)
		return (NULL);
	if (!s1[0] && !s2[0])
		return ("");
	i1 = 0;
	while (s1[i1] && i1 < n)
	{
		i2 = 0;
		while (s2[i2] == s1[i1 + i2] && s2[i2] && s1[i1])
			i2++;
		if (i1 + i2 > n)
			return (NULL);
		if (s2[i2] == '\0')
			return ((char *)&s1[i1]);
		if (s1[i1 + i2] == '\0')
			return (NULL);
		i1++;
	}
	return (NULL);
}
