/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:36:33 by srison            #+#    #+#             */
/*   Updated: 2014/11/08 12:38:04 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		index;

	index = strlen(str);
	while (index)
	{
		if (str[index] == c)
			return ((char *)&str[index]);
		index--;
	}
	return (NULL);
}
