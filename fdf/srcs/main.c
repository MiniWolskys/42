/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:11:51 by srison            #+#    #+#             */
/*   Updated: 2015/01/22 08:11:52 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx		*mlx_struct;
	t_pos		*size;
	int			**map;

	if (ac < 2)
		return (1);
	if (!(map = get_map(av[1], &size)))
		return (1);
	ft_putstr("Size de x : ");
	ft_putnbr(size->x);
	ft_putendl(".");
	ft_putstr("Size de y : ");
	ft_putnbr(size->y);
	ft_putendl(".");
	if (!(mlx_struct = (t_mlx *)ft_memalloc(sizeof(*mlx_struct))))
		return (1);
	if (!(init_mlx_struct(&mlx_struct)))
		return (1);
	if (!(read_map(&(mlx_struct), map, size)))
		return (1);
	if (!(get_event(mlx_struct/*, map, size*/)))
		return (1);
	return (0);
}
