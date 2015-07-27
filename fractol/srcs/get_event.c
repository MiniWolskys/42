/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 17:05:11 by srison            #+#    #+#             */
/*   Updated: 2015/02/22 17:05:14 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

int				expose_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

static void		arrow_hook(int keypress, t_mlx *mlx)
{
	if (keypress == 123)
		mlx->x -= 5;
	else if (keypress == 124)
		mlx->x += 5;
	else if (keypress == 125)
		mlx->y += 5;
	else if (keypress == 126)
		mlx->y -= 5;
	else if (keypress == 83)
		mlx->set = 0;
	else if (keypress == 84)
		mlx->set = 1;
	else if (keypress == 85)
		mlx->set = 2;
	else if (keypress == 86)
		mlx->set = 3;
	else if (keypress == 87)
		mlx->set = 4;
	else if (keypress == 88)
		mlx->set = 5;
	else if (keypress == 89)
		mlx->set = 6;
	else if (keypress == 91 || keypress == 92)
		mlx->set = keypress == 91 ? 7 : 8;
}

void			redraw_mlx(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	reset_image(mlx);
	if (mlx->fractal == 1)
		draw_mandel(mlx);
	else if (mlx->fractal == 2)
		draw_julia(mlx);
	else if (mlx->fractal == 3)
		draw_ship(mlx);
	expose_hook(mlx);
}

static int		key_hook(int keypress, t_mlx *mlx)
{
	if (keypress == 53)
		exit(0);
	else if ((keypress >= 123 && keypress <= 126) || (keypress > 82 &&
		keypress < 93 && keypress != 90))
		arrow_hook(keypress, mlx);
	else if (keypress == 69)
		mlx->fractal += (mlx->fractal == 3) ? -2 : 1;
	else if (keypress == 78)
		mlx->fractal += (mlx->fractal == 1) ? 2 : -1;
	if (keypress == 78 || keypress == 69)
		keypress = 49;
	if (keypress == 67 || keypress == 75)
		mlx->iter += (keypress == 67) ? 1 : (!mlx->iter) ? 0 : -1;
	if (keypress == 49)
	{
		mlx->zoom = 1;
		mlx->x = 0;
		mlx->y = 0;
	}
	else if ((keypress <= 122 || keypress >= 127) && (keypress < 82 ||
		keypress > 93 || keypress == 90) && keypress != 75 && keypress != 67)
		return (0);
	redraw_mlx(mlx);
	return (1);
}

void			get_event(t_mlx *mlx)
{
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->h, mlx->w, "test")))
		return ;
	expose_hook(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_expose_hook(mlx->win, expose_hook, mlx);
//	if (mlx->fractal == 2)
//		mlx_hook(mlx->win, 8, 1L<<8, mouse_move, mlx);
	mlx_loop(mlx->mlx);
}
