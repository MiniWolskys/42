/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 23:06:11 by srison            #+#    #+#             */
/*   Updated: 2015/01/12 23:06:14 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_get_file(int fd)
{
	int		out;
	char	*str;
	char	*result;
	char	*mem;
	char	**file;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	out = BUFF_SIZE;
	if (!(result = ft_strnew(0)))
		return (NULL);
	while (out == BUFF_SIZE)
	{
		if (!(str = ft_strnew(BUFF_SIZE)) ||
			((out = read(fd, str, BUFF_SIZE)) == -1) ||
			(!(mem = ft_strjoin(result, str))))
			return (NULL);
		result = mem;
		free(str);
	}
	file = ft_split_line(result, '\n');
	free(result);
	return (file);
}
