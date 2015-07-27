/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 18:47:46 by srison            #+#    #+#             */
/*   Updated: 2015/07/08 18:47:47 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "mlx.h"
#include "libft.h"

static int		expose_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}

static int		keyrelease_hook(int keypress, t_mlx *mlx)
{
	t_vec		tmp;

	if (keypress < 123 || keypress > 126)
		return (1);
	tmp.x = mlx->pos.x;
	tmp.y = mlx->pos.y;
	if (keypress == 123 || keypress == 124)
		tmp.x += keypress == 123 ? -0.1 : 0.1;
	else if (keypress == 125 || keypress == 126)
		tmp.y += keypress == 125 ? -0.1 : 0.1;
	if (!draw(mlx, tmp))
		return (1);
	expose_hook(mlx);
	mlx->pos.x = tmp.x;
	mlx->pos.y = tmp.y;
	return (1);
}

static int		mousemove_hook(int x, int y, t_mlx *mlx)
{
	if (x == 0)
		return (1);
	mlx->dir += (x > mlx->m_x) ? 1 : -1;
	if (mlx->dir > 360)
		mlx->dir = 0;
	else if (mlx->dir < 0)
		mlx->dir = 360;
	mlx->m_x = x + ((x > mlx->m_x) ? -1 : 1);
	draw(mlx, mlx->pos);
	expose_hook(mlx);
	return (y);
}

static int		key_hook(int keypress, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (keypress == 53)
		exit(1);
	return (1);
}

void			manage_event(t_mlx *mlx)
{
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 2, 1L << 2, keyrelease_hook, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mousemove_hook, mlx);
	mlx_loop(mlx->mlx);
}
