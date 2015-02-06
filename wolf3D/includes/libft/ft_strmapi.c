/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:21:01 by srison            #+#    #+#             */
/*   Updated: 2014/11/05 17:34:03 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	index;

	index = 0;
	dest = ft_strnew(ft_strlen(s));
	while (s[index])
	{
		dest[index] = f(index, s[index]);
		index++;
	}
	return (dest);
}
