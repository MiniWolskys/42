/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 14:55:45 by srison            #+#    #+#             */
/*   Updated: 2015/01/03 07:11:41 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	char	**file;
	t_mlx	e;
	int		**map;
	t_pos	*size;

	size = NULL;
	if (ac < 2)
		return (!ft_put_error(av[0], NULL, 4) ? 0 : 1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (!ft_put_error(av[0], av[1], 1) ? 0 : 1);
	if (!(file = ft_get_file(fd, &size)))
		return (1);
	close(fd);
	if (!(map = ft_aatoai(file, size->y)))
		return (1);
	if (!(e.mlx = mlx_init()) || (!(e.win =
		(mlx_new_window(e.mlx, size->x * 50, size->y * 50, av[1])))))
		return (1);
	if (!(print_map(map, e)))
		return (1);
	sleep(5);
//	if (!(get_event(map, size)))
//		return (1);
	return (0);
}
