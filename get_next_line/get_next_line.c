/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 08:12:15 by srison            #+#    #+#             */
/*   Updated: 2015/06/29 23:50:33 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			loop(char **str, int out, int fd, char **line)
{
	int		i;

	i = -1;
	while (out != -1 && out && ++i > -1)
	{
		if ((*str)[i] == '\n')
		{
			if (!(*line = ft_strjoin(*line, ft_strndup(*str, i))))
				return (-1);
			(*str) = &((*str)[i + 1]);
			return (1);
		}
		if (!((*str)[i]))
		{
			if (!(*line = ft_strjoin(*line, *str)))
				return (-1);
			if (!(*str = ft_strnew(BUFF_SIZE)))
				return (-1);
			if ((out = read(fd, *str, BUFF_SIZE)) == -1)
				return (-1);
			i = -1;
		}
	}
	return (out);
}

int			get_next_line(int const fd, char **line)
{
	static char		*str[32];
	int				out;

	if (fd < 0 || fd == 1 || fd == 2 || !line)
		return (-1);
	*line = ft_strnew(1);
	**line = '\0';
	out = 1;
	if (!str[fd])
	{
		if (!(str[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((out = read(fd, str[fd], BUFF_SIZE)) == -1)
			return (-1);
	}
	out = loop(&(str[fd]), out, fd, line);
	if (out > 0)
		out = 1;
	return (out);
}
