/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:11:40 by srison            #+#    #+#             */
/*   Updated: 2015/02/22 15:11:41 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					img_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char				*pixel;

	if ((x + 4 > mlx->w || x < 0) || (y + 4 > mlx->h || y < 0))
		return ;
	pixel = mlx->data + x * mlx->sl + (mlx->bpp / 8) * y;
	pixel[3] = 0;
	pixel[2] = (color >> 8) & 0xFF;
	pixel[1] = (color >> 16) & 0xFF;
	pixel[0] = (color >> 24) & 0xFF;
}
