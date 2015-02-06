/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:12:02 by srison            #+#    #+#             */
/*   Updated: 2015/01/22 08:12:04 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init_mlx_struct(int image)
{
	t_mlx		*mlx_struct;

	if (!(mlx_struct->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(mlx_struct->win_ptr =
		mlx_new_window(mlx_struct->mlx_ptr, 500, 500, "srison.fdf")))
		return (NULL);
	if (image)
		mlx_struct->img_struct = init_img_struct();
	else
		mlx_struct->img_struct = NULL;
	return (1);
}
