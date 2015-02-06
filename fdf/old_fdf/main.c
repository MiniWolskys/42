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

static char	**read_file(char *src, char *name, t_pos **size)
{
	int		fd;
	char	**file;

	if ((fd = open(src, O_RDONLY)) == -1)
		return (!ft_put_error(name, src, 1) ? NULL : NULL);
	if (!(file = ft_get_file(fd, size)))
		return (NULL);
	close(fd);
	return (file);
}

int			main(int ac, char **av)
{
	char	**file;
	int		**map;
	t_mlx	window;
	t_mlx	image;
	t_pos	*size;

	size = NULL;
	if (ac < 2)
		return (!ft_put_error(av[0], NULL, 4) ? 0 : 1);
	if (!(file = read_file(av[1], av[0], &size)))
		return (1);
	if (!(map = ft_aatoai(file, size->y)))
		return (1);
	if (!(window.mlx = mlx_init()))
		return (1);
	image.mlx = window.mlx;
	if ((!(image.win = (mlx_new_image(image.mlx, size->x * 50, size->y * 50)))))
		return (1);
	ft_putendl("print_map start now.");
	if (!(print_map(map, image)))
		return (1);
	ft_putendl("print_map is over, get_event start now!");
	get_event(window, image.win, size, av[1]);
	ft_putendl("Program is over.");
	return (0);
}
