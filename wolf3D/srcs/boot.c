/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 19:39:20 by srison            #+#    #+#             */
/*   Updated: 2015/07/08 19:39:21 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wolf.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>

static t_mlx	*get_info(t_mlx *mlx)
{
	mlx->pos.x = 5.5;
	mlx->pos.y = 5.5;
	mlx->pos_z = 1.0;
	mlx->m_x = 10;
	mlx->dir = 0;
	return (mlx);
}

t_mlx			*boot(void)
{
	t_mlx		*mlx;
	int			fd;

	if (!(mlx = ft_memalloc(sizeof(mlx) + 1)))
		return (NULL);
	if ((fd = open("./map/map.txt", O_RDONLY)) == -1)
	{
		ft_putendl("No such map.");
		ft_memdel((void **)&mlx);
		return (NULL);
	}
	mlx->map = ft_get_file(fd);
	close(fd);
	if (!(mlx->mlx = mlx_init()))
		return (NULL);
	if (!(mlx->win = mlx_new_window(mlx->mlx, SCREEN_SIZE, 2 * SCREEN_SIZE / 3,
		"test")))
		return (NULL);
	if (!(mlx->img = mlx_new_image(mlx->mlx, SCREEN_SIZE, 2 * SCREEN_SIZE / 3)))
		return (NULL);
	if (!(mlx->data =
		mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->m_x)))
		return (NULL);
	mlx = get_info(mlx);
	return (mlx);
}
