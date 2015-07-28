/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 18:11:02 by srison            #+#    #+#             */
/*   Updated: 2014/11/18 18:33:15 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelchar(char const *str, char c)
{
	char	*dst;
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] != c)
			count++;
		index++;
	}
	dst = ft_strnew(count);
	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] != c)
		{
			dst[count] = str[index];
			count++;
		}
		index++;
	}
	return (dst);
}
