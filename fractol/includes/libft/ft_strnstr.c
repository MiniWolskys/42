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

static char	*ft_teststrnstr(const char *s1, const char *s2, int n, int index)
{
	int		i;

	i = 0;
	if (s1[index] == '\0')
		return (NULL);
	while (s1[index + i] == s2[i])
	{
		if (i == n)
			return ((char *)&s1[index]);
		if (s1[index + i] == '\0')
			return (NULL);
		i++;
	}
	if (i == n)
		return ((char *)&s1[index]);
	return (ft_teststrnstr(s1, s2, n, index + 1));
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (ft_strlen(s2) <= n)
		return (ft_strstr(s1, s2));
	return (ft_teststrnstr(s1, s2, n, 0));
}
