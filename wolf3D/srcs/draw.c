/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 01:35:23 by srison            #+#    #+#             */
/*   Updated: 2015/07/27 01:35:25 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"
#include <stdio.h>

int		draw(t_mlx *mlx, t_vec pt_cam)
{
	t_pos	pos;
	int		length;
	int		angle;

	
	angle = mlx->dir - 31;
	printf("pos : (%f; %f)\n", pt_cam.x, pt_cam.y);
	while (++angle <= mlx->dir + 30)
	{
		length = (int)(get_wall_distance(angle, pt_cam, mlx->map) * 100.0) / 100;
		if (length == 0 || (mlx->map[(int)pt_cam.x][(int)pt_cam.y] != '0'))
			return (0);
		pos.x = -1;
		while (++(pos.x) != 20)
		{
			pos.y = -1;
			while (++(pos.y) != 1201)
			{
			//	put_pixel(mlx, pos.x + 20 * (angle - mlx->dir + 30), pos.y, ft_set_color(255, 0, 0));
				if (pos.y > 10 * length && pos.y < 1200 - 10 * length)
					put_pixel(mlx, pos.y, pos.x + 20 * (angle - mlx->dir + 30), 0x00ffff00);
				else
					put_pixel(mlx, pos.y, pos.x + 20 * (angle - mlx->dir + 30), 0x00000000);
			}
		}
	}
	return (1);
}
