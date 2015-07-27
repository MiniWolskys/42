/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:51:00 by srison            #+#    #+#             */
/*   Updated: 2015/02/17 18:23:53 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

static int		get_color(t_mlx *mlx, int i)
{
	if (!mlx->set)
		return ((i == MAX) ? set_color(0, 0, 0) : set_color(i * 10, 0, 0));
	else if (mlx->set == 3)
		return ((i == MAX) ? set_color(255, 255, 255) :
			set_color(0, 0, i * 10));
	else if (mlx->set == 4)
		return ((i == MAX) ? set_color(255, 255, 255) :
			set_color(0, i * 10, 0));
	else if (mlx->set == 1)
		return ((i == MAX) ? set_color(0, 0, 0) : set_color(0, 0, i * 10));
	else if (mlx->set == 2)
		return ((i == MAX) ? set_color(0, 0, 0) : set_color(0, i * 10, 0));
	else if (mlx->set == 5)
		return ((i == MAX) ? set_color(255, 255, 255) :
			set_color(i * 10, 0, 0));
	else if (mlx->set == 6)
		return ((i == MAX) ? set_color(0, 255, 0) :
			set_color(i * 30, i * 20, i * 10));
	else if (mlx->set == 7)
		return ((i == MAX) ? set_color(0, 0, 0) : set_color(i * 20, i * 16, 0));
	else if (mlx->set == 8)
		return ((i == MAX) ? set_color(255, 255, 255) :
			set_color(i * 20, i * 16, 0));
	return (0);
}

static void		next_mandel(t_mlx *mlx, t_vec pos)
{
	int			color;
	int			i;
	t_vec		z;
	double		tmp;

	i = -1;
	z.x = 0;
	z.y = 0;
	while (++i < MAX && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + pos.x;
		z.y = 2 * z.y * tmp + pos.y;
	}
	color = get_color(mlx, i);
	img_pixel_put(mlx, (pos.y * 100 + mlx->y) * mlx->zoom + 500,
		(pos.x * 100 + mlx->x) * mlx->zoom + 500, color);
}

void			draw_mandel(t_mlx *mlx)
{
	t_vec				pos;
	t_vec				lim;

	pos.x = -2.1;
	lim.x = 0.6;
	lim.y = 1.2;
	while (pos.x < lim.x)
	{
		pos.y = -1.2;
		while (pos.y < lim.y)
		{
			next_mandel(mlx, pos);
			pos.y += 0.01 * mlx->iter;
		}
		pos.x += 0.01 * mlx->iter;
	}
}
