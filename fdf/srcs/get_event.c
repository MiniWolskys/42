/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 06:26:54 by srison            #+#    #+#             */
/*   Updated: 2015/01/24 06:26:55 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static int	key_hook(int keycode, t_mlx *mlx_struct)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 35361)
		mlx_struct->img_pos_win->x -= 5;
	else if (keycode == 35362)
		mlx_struct->img_pos_win->y += 5;
	else if (keycode == 35363)
		mlx_struct->img_pos_win->x += 5;
	else if (keycode == 35364)
		mlx_struct->img_pos_win->y -= 5;
	mlx_clear_window(mlx_struct->mlx_ptr, mlx_struct->win_ptr);
	mlx_put_image_to_window(mlx_struct->mlx_ptr, mlx_struct->win_ptr,
		mlx_struct->struct_img, mlx_struct->img_pos_win->x,
		mlx_struct->img_pos_win->y);
	return (1);
}
*/
int			get_event(t_mlx *mlx_struct/*, int **map, t_pos *size*/)
{
	mlx_put_image_to_window(mlx_struct->mlx_ptr, mlx_struct->win_ptr,
		mlx_struct->struct_img->img_ptr, 0, 0);
//	mlx_key_hook(mlx_struct->win_ptr, key_hook, mlx_struct);
//	mlx_loop(mlx_struct->win_ptr);
	sleep(5);
	return (1);
}