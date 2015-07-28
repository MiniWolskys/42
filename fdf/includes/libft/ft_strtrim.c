/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:58:12 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 16:45:33 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_end(char const *s, size_t index1)
{
	while (s[index1] == '\t' || s[index1] == '\n' || s[index1] == ' ')
		index1++;
	if (s[index1] == '\0')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char			*dest;
	unsigned int	index1;
	unsigned int	index2;

	index1 = 0;
	index2 = 0;
	dest = ft_strnew(ft_strlen(s));
	if (!dest)
		return (NULL);
	while (s[index1])
	{
		if (index1 == 0)
			while (s[index1] == '\t' || s[index1] == '\n' || s[index1] == ' ')
				index1++;
		if (s[index1] == '\t' || s[index1] == '\n' || s[index1] == ' ')
			if (ft_trim_end(s, index1))
				return (dest);
		dest[index2] = s[index1];
		index1++;
		index2++;
	}
	return (dest);
}
