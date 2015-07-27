/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:12:47 by srison            #+#    #+#             */
/*   Updated: 2015/01/02 00:56:09 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "libft.h"
#include "mlx.h"

static int		init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		return (0);
	mlx->h = WIN_HEIGHT;
	mlx->w = WIN_WIDTH;
	if (!(mlx->img = mlx_new_image(mlx->mlx, mlx->w, mlx->h)))
		return (0);
	if (!(mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
		&mlx->sl, &mlx->x)))
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		return (0);
	}
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 1.0;
	mlx->set = 0;
	mlx->iter = 1;
	return (1);
}

static int		get_fractal(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (len < 3)
		return (0);
	if (!ft_strncmp(name, "julia", len))
		return (2);
	if (!ft_strncmp(name, "mandelbrot", len))
		return (1);
	if (!ft_strncmp(name, "burning_ship", len))
		return (3);
	return (0);
}

int				main(int ac, char **av)
{
	t_mlx		mlx;
	int			fractal;

	if (ac == 2)
	{
		if (!(fractal = get_fractal(av[1])))
		{
			ft_putendl("Error : unknow parameter. Type \"./fractol\" for help");
			return (1);
		}
		else if (!(init_mlx(&mlx)))
			return (1);
		else if (fractal == 1)
			draw_mandel(&mlx);
		else if (fractal == 2)
			draw_julia(&mlx);
		else if (fractal == 3)
			draw_ship(&mlx);
		mlx.fractal = fractal;
		mlx_do_key_autorepeaton(mlx.mlx);
		get_event(&mlx);
	}
	else
		ft_putendl("Error : should be \"./fractol [mandel|julia|ship]\"");
	return (0);
}
