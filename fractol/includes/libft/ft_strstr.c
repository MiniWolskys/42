/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:45:14 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 16:45:19 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_teststrstr(const char *s1, const char *s2, int i1, int i2)
{
	if (s2[i2] == '\0')
		return ((char *)&s1[i1]);
	if (s1[i1] == '\0')
		return (NULL);
	if (s1[i1 + i2] != s2[i2])
		return (ft_teststrstr(s1, s2, i1 + 1, 0));
	if (s1[i1 + i2] == s2[i2])
		return (ft_teststrstr(s1, s2, i1, i2 + 1));
	return (NULL);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	return (ft_teststrstr(s1, s2, 0, 0));
}
