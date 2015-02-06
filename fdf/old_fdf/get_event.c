/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:56:19 by srison            #+#    #+#             */
/*   Updated: 2015/01/19 14:56:21 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_mlx *window, t_pos **place, void *img_ptr)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 35361)
		(*place)->x -= 5;
	else if (keycode == 35362)
		(*place)->y += 5;
	else if (keycode == 35363)
		(*place)->x += 5;
	else if (keycode == 35364)
		(*place)->y -= 5;
	mlx_clear_window(window->mlx, window->win);
	mlx_put_image_to_window(window->mlx, window->mlx, img_ptr, (*place)->x, (*place)->y);
	return (1);
}

void		get_event(t_mlx window, void *image, t_pos *size, char *name)
{
	char	*n_name;
	t_pos	*pos;

	if (!(pos = (t_pos *)ft_memalloc(sizeof(*pos))))
		return ;
	if (!(n_name = ft_strjoin("42.fdf - ", name)))
		return ;
	if (!(window.win = mlx_new_window(window.mlx, size->x * 50, size->y * 50, n_name)))
		return ;
	free(n_name);
	mlx_put_image_to_window(window.mlx, window.win, image, 0, 0);
	mlx_key_hook(window.win, key_hook, &window);
	mlx_loop(window.mlx);
}
