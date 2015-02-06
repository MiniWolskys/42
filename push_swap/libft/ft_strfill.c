/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:53:06 by srison            #+#    #+#             */
/*   Updated: 2014/12/02 17:53:08 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *str, char c)
{
	int		size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	while (size >= 0)
	{
		str[size] = c;
		size--;
	}
	return (str);
}
