/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 04:26:22 by srison            #+#    #+#             */
/*   Updated: 2014/12/29 21:17:34 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_point(double x, double y, t_mlx e)
{
	int		count;
	double	z_r;
	double	z_i;
	double	tmp;

	count = 0;
	z_r = 0;
	z_i = 0;
	while (count < 50 && (z_r * z_r + z_i * z_i) < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - (z_i * z_i) + x;
		z_i = 2 * z_i * tmp + y;
		count++;
	}
	if (count < 50)
		mlx_pixel_put(e.mlx, e.win, (x *100 + 200), (y * 100 + 250),
			set_color(0, 0, count * 5));
}

static void	mlx_draw(t_mlx e)
{
	t_pos	pos;
	t_pos	start;
	t_pos	end;

	pos.x = 0;
	pos.y = 0;
	start.x = -2.1;
	start.y = -1.2;
	end.x = 0.6;
	end.y = 1.2;
	while (pos.x + start.x <= end.x)
	{
		get_point(pos.x + start.x, pos.y + start.y, e);
		if (pos.y + start.y > end.y)
		{
			pos.x += 0.001;
			pos.y = 0;
		}
		pos.y += 0.001;
	}
}

int			main()
{
	t_mlx	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "42.fr");
	mlx_draw(e);
	sleep(5);
	return (0);
}
