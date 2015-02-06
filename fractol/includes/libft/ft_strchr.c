/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:42:21 by srison            #+#    #+#             */
/*   Updated: 2014/11/08 12:37:49 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return ((char *)&str[index]);
		index++;
	}
	return (NULL);
}
