/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:07:24 by srison            #+#    #+#             */
/*   Updated: 2015/01/30 12:10:17 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void		destroy_image(t_mlx **mlx);
{
	if (!mlx || !(*mlx) || !(*mlx)->img_struct)
		return ;
	if ((*mlx)->img_struct->data)
		free((*mlx)->img_struct->data);
	mlx_destroy_image((*mlx)->mlx_ptr, (*mlx)->img_struct->img_ptr);
	free(&((*mlx)->img_struct));
	return ;
}
