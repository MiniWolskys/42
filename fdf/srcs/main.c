/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 03:08:02 by srison            #+#    #+#             */
/*   Updated: 2015/04/03 03:08:04 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>

static t_mlx		*init_mlx(t_pos *size, int **map)
{
	t_mlx			*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(*mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()))
		return (NULL);
	mlx->pos_x = 0;
	mlx->pos_y = 0;
	mlx->w = MLX_WIDTH;
	mlx->h = MLX_HEIGHT;
	mlx->size_x = size->x;
	mlx->size_y = size->y;
	mlx->map = map;
	mlx->zoom = 1;
	mlx->cste = 1.5;
	if (!(mlx->win =
		mlx_new_window(mlx->mlx, MLX_WIDTH, MLX_HEIGHT, "Bisoir.")))
		return (NULL);
	return (mlx);
}

static void			free_file(char **file)
{
	int				i;

	i = -1;
	while (file[++i])
		free(file[i]);
	free(file);
}

static int			**get_map(char *path)
{
	char			**file;
	int				**map;
	int				fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putendl("File was not found.");
		return (NULL);
	}
	if (!(file = ft_get_file(fd)))
		return (NULL);
	if (!check_file(file))
	{
		free_file(file);
		ft_putendl("Invalid file. Aborted.");
		return (NULL);
	}
	map = ft_aatoai(file);
	free_file(file);
	if (!map)
	{
		ft_putendl("Error reading the map.");
		return (NULL);
	}
	return (map);
}

int					main(int ac, char **av)
{
	t_pos			*size;
	t_mlx			*mlx;
	int				**map;

	if (ac != 2)
	{
		ft_putendl("Usage :\nfdf <map.fdf>\nYou can use only one map.");
		return (0);
	}
	if (!(map = get_map(av[ac - 1])))
		return (1);
	if (!(size = (t_pos *)ft_memalloc(sizeof(*size))))
		return (0);
	size->x = 0;
	size->y = 0;
	while (map[size->x])
		(size->x)++;
	while (map[0][size->y])
		(size->y)++;
	if (!(mlx = init_mlx(size, map)))
		return (1);
	if (!(use_mlx(mlx)))
		return (1);
	ft_memdel((void *)size);
	return (0);
}
