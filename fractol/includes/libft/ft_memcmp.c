/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:40:56 by srison            #+#    #+#             */
/*   Updated: 2014/11/08 18:02:07 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;
	char	*str1;
	char	*str2;

	index = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (index < n && str1[index] && (str1[index] == str2[index]))
		index++;
	return (str1[index] - str2[index]);
}
