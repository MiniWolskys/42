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

static t_pos	*get_size(char *result, t_pos *size)
{
	int		i;
	int		cur_size;

	if (!(size = (t_pos *)ft_memalloc(sizeof(*size))))
		return (NULL);
	i = 0;
	size->y = 0;
	size->x = 0;
	cur_size = 0;
	while (result[i])
	{
		if (result[i] == '\n')
		{
			(size->y)++;
			size->x = (size->x > cur_size) ? size->x : cur_size;
			cur_size = -1;
		}
		cur_size++;
		i++;
	}
	return (size);
}

char			**ft_get_file(int fd, t_pos **size)
{
	int		out;
	char	*str;
	char	*result;
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
			(!(result = ft_strjoin(result, str))))
			return (NULL);
		free(str);
	}
	if (!(*size = get_size(result, *size)))
		return (NULL);
	file = ft_split_line(result, '\n');
	free(result);
	return (file);
}
