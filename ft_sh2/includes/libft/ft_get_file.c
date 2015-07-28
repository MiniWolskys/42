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
	int		cnt;
	int		cur_size;
	int		max_size;

	i = -1;
	cnt = 1;
	max_size = 0;
	cur_size = 0;
	if (!(size = (t_pos *)ft_memalloc(sizeof(*size))))
		return (NULL);
	while (result[++i])
	{
		if (result[i] == '\n')
		{
			if (result[i + 1] != '\n')
				cnt++;
			max_size = (max_size > cur_size) ? max_size : cur_size;
			cur_size = -1;
		}
		cur_size++;
	}
	size->x = max_size;
	size->y = cnt;
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
		if (!(str = ft_strnew(BUFF_SIZE)))
			return (NULL);
		if ((out = read(fd, str, BUFF_SIZE)) == -1)
			return (NULL);
		if (!(result = ft_strjoin(result, str)))
			return (NULL);
		free(str);
	}
	if (!(*size = get_size(result, *size)))
		return (NULL);
	file = ft_split_line(result, '\n');
	free(result);
	return (file);
}
