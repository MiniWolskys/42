/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 14:14:57 by srison            #+#    #+#             */
/*   Updated: 2015/01/25 14:14:59 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int			mlx_move_img(t_mlx **mlx_struct, int move_x, int move_y)
{
	if (!mlx_clear_window((*mlx)->mlx_ptr, (*mlx)->win_ptr))
		return (0);
	(*mlx)->pos_height += move_y;
	(*mlx)->pos_width += move_x;
	if (!mlx_put_image_to_window((*mlx)->mlx_ptr, (*mlx)->win_ptr,
		(*mlx)->img_struct->img_ptr, (*mlx)->pos_height, (*mlx)->pos_width))
	{
		destroy_window(mlx_struct);
		return (0);
	}
	return (1);
}
