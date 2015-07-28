/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:42:27 by srison            #+#    #+#             */
/*   Updated: 2014/11/08 11:58:57 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char const *s1)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(s1));
	dest = ft_strcpy(dest, s1);
	return (dest);
}
