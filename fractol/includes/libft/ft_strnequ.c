/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:30:50 by srison            #+#    #+#             */
/*   Updated: 2014/11/07 20:55:25 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	n--;
	while (s1[index] && s2[index] && (index < n))
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	if (s1[index] != s2[index])
		return (0);
	return (1);
}
