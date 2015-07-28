/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmakepath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 19:12:58 by srison            #+#    #+#             */
/*   Updated: 2014/12/14 19:12:59 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmakepath(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, "/");
	tmp = ft_strjoin(tmp, s2);
	return (tmp);
}
