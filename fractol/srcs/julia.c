/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 21:04:30 by srison            #+#    #+#             */
/*   Updated: 2015/05/12 21:04:31 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

static void		next_julia(t_mlx *mlx, t_vec pos)
{
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
	if (i == MAX)
		img_pixel_put(mlx, pos.y * 100 + 500, pos.x * 100 + 500,
			(!mlx->set) ? set_color(255, 255, 255) : set_color(0, 0, 0));
	else if (i != MAX)
		img_pixel_put(mlx, pos.y * 100 + 500, pos.x * 100 + 500,
			(!mlx->set) ? set_color(0, 0, 10 * i) : set_color(10 * i, 0, 0));
}

void			draw_julia(t_mlx *mlx)
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
			next_julia(mlx, pos);
			pos.y += 0.01 / mlx->zoom;
		}
		pos.x += 0.01 / mlx->zoom;
	}
}
