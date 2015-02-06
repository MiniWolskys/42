/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:46:34 by srison            #+#    #+#             */
/*   Updated: 2015/01/30 12:46:35 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_img		*init_img(size_t height, size_t width)
{
	t_img		*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(*img))))
		return (NULL)
}

t_mlx		*init_mlx(size_t height, size_t width, char *name, int image)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(*mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()))
	{
		free(mlx);
		return (NULL);
	}
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, name)))
	{
		free(mlx);
		return (NULL);
	}
	if (!image)
		mlx->img_struct = NULL;
	else
		if (!(mlx->img_struct = init_img(height, width)))
		{
			free(mlx);
			return (NULL);
		}
	mlx->win_height = height;
	mlx->win_width = width;
	mlx->pos_height = 0;
	mlx->pos_width = 0;
	return (mlx);
}
