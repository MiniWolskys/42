/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:26:13 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 23:15:28 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	n;
	int				size;

	n = 0;
	size = ft_strlen(s1);
	while (s2[n])
	{
		s1[n + size] = s2[n];
		n++;
	}
	s1[size + n] = '\0';
	return (s1);
}
