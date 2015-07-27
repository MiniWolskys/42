/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 01:24:55 by srison            #+#    #+#             */
/*   Updated: 2015/07/09 01:24:57 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= SCREEN_SIZE || y >= 2 * SCREEN_SIZE / 3)
		return ;
	pixel = mlx->data + x * mlx->sl + (mlx->bpp / 8) * y;
	pixel[3] = 0;
	pixel[2] = (color >> 8) & 0xFF;
	pixel[1] = (color >> 16) & 0xFF;
	pixel[0] = (color >> 24) & 0xFF;
}
