/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:09:37 by srison            #+#    #+#             */
/*   Updated: 2014/11/05 17:34:16 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		index;

	index = 0;
	dest = ft_strnew(ft_strlen(s));
	while (s[index])
	{
		dest[index] = f(s[index]);
		index++;
	}
	return (dest);
}
