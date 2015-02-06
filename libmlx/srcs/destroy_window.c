/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 10:54:47 by srison            #+#    #+#             */
/*   Updated: 2015/01/30 12:07:04 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void		destroy_window(t_mlx **mlx)
{
	if (!mlx)
		return ;
	mlx_destroy_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	if ((*mlx)->img_struct)
		destroy_img(&((*mlx)->img_struct));
	free(mlx);
	return ;
}
