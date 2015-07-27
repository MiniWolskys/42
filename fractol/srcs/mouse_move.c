/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 04:20:32 by srison            #+#    #+#             */
/*   Updated: 2015/05/14 04:20:33 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int				mouse_hook(int buttonpress, int x, int y, t_mlx *mlx)
{
	if (buttonpress == 5 && mlx->zoom > 0.1)
		mlx->zoom += 0.1;
	if (buttonpress == 4)
		mlx->zoom -= 0.1;
	if (buttonpress != 5 && buttonpress != 4 && buttonpress != 1)
		return (0);
	redraw_mlx(mlx);
	if (!x && !y)
		return (0);
	return (1);
}

/*

int				mouse_move(int x, int y, t_mlx *mlx)
{
	printf("Mouse moved in : x = %d y = %d\n", x, y);
	if (!x && !y && !mlx)
		return (0);
	return (1);
}

*/