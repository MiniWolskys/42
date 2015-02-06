/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:17:48 by srison            #+#    #+#             */
/*   Updated: 2014/11/09 13:38:02 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*dest;

	index = 0;
	dest = (char *)s;
	if (!(n))
		return ;
	while (dest[index] && (index < n))
	{
		dest[index] = '0';
		index++;
	}
	return ;
}
