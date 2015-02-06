/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memeset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:56:17 by srison            #+#    #+#             */
/*   Updated: 2014/11/08 17:33:36 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memeset(void *b, int c, size_t len)
{
	size_t		index;
	char		*result;

	result = (char *)b;
	index = 0;
	while (result[index] && index < len)
	{
		result[index] = (char)c;
		index++;
	}
	return (b);
}
