/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:48:12 by srison            #+#    #+#             */
/*   Updated: 2014/11/08 12:40:13 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		size;

	if (n == 0)
		return (s1);
	index = 0;
	size = ft_strlen(s1);
	while ((s2[index]) && (index <= n - 1))
	{
		s1[index + size] = s2[index];
		index++;
	}
	s1[index + size] = '\0';
	return (s1);
}
