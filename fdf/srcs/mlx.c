/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 17:38:29 by srison            #+#    #+#             */
/*   Updated: 2015/04/28 17:38:31 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <unistd.h>

static int			useless(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

static t_mlx		*calc(t_mlx *mlx)
{
	if (!(mlx->img = mlx_new_image(mlx->mlx, MLX_WIDTH, MLX_HEIGHT)))
		return (NULL);
	if (!(mlx->data =
		mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->endian)))
		return (NULL);
	draw_calc(mlx->map, mlx);
	useless(mlx);
	return (mlx);
}

static void			get_arrow(int keypress, t_mlx *mlx)
{
	if (keypress == 123 || keypress == 124)
		mlx->pos_y += keypress == 123 ? 10 : -10;
	else if (keypress == 125 || keypress == 126)
		mlx->pos_x += keypress == 125 ? 10 : -10;
	else if (keypress == 69)
		mlx->zoom /= 2;
	else if (keypress == 78)
		mlx->zoom *= 2;
	else if (keypress == 67 || keypress == 75)
		mlx->cste += (keypress == 67) ? 0.2 : -0.2;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx = calc(mlx);
}

static int			key_hook(int keypress, t_mlx *mlx)
{
	if (keypress == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		ft_memdel((void *)mlx->data);
		mlx_destroy_window(mlx->mlx, mlx->win);
		ft_memdel((void *)mlx);
		exit(0);
	}
	else if ((keypress >= 123 && keypress <= 126) || keypress == 78 ||
		keypress == 69 || keypress == 67 || keypress == 75)
		get_arrow(keypress, mlx);
	else if (keypress == 49)
	{
		mlx->pos_x = 0;
		mlx->pos_y = 0;
		mlx->zoom = 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx = calc(mlx);
	}
	return (0);
}

int					use_mlx(t_mlx *mlx)
{
	if (!(mlx = calc(mlx)))
		return (0);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_expose_hook(mlx->win, useless, mlx);
	mlx_loop(mlx->mlx);
	return (1);
}
