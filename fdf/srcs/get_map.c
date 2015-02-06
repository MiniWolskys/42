/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 09:03:11 by srison            #+#    #+#             */
/*   Updated: 2015/01/22 09:03:12 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**get_map(char *file, t_pos **size)
{
	int		fd;
	int		**map;
	char	**tab_file;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(tab_file = ft_get_file(fd, size)))
		return (NULL);
	close(fd);
	if (!(map = ft_aatoai(tab_file, *size)))
		return (NULL);
	free(tab_file);
	return (map);
}
