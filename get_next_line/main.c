/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 18:09:51 by srison            #+#    #+#             */
/*   Updated: 2015/06/29 23:52:54 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int				main(int ac, char **av)
{
	char		*line;
	int			fd;
	int			fd2;
	int			ret;

	if (ac > 1)
	{
		if ((fd = open(av[ac - 1], O_RDONLY)) == -1)
			return (1);
	}
	else
		fd = 0;
	fd2 = open("get_next_line.c", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (1);
		ft_putendl(line);
		free(line);
		ret = get_next_line(fd2, &line);
		if (ret == -1)
			return (1);
		ft_putendl(line);
		free(line);
	}
	return (0);
}
