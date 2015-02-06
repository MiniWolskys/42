/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 23:28:05 by srison            #+#    #+#             */
/*   Updated: 2015/01/23 23:28:15 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			pixel_put_mlx(t_img **img, int x, int y)
{
	int		color;

	color = 0xFFFFFFFF;
	(*img)->data[(*img)->size_line * y + x * (*img)->bpp] = color;
}

t_vec			get_vec(t_pos *pos1, t_pos *pos2, int *size)
{
	t_vec		vec;
	t_pos		diff;

	diff.x = pos2->x - pos1->x;
	diff.y = pos2->y - pos1->y;
	if (ABS(diff.x) == ABS(diff.y))
	{
		vec.x = (diff.x > 0) ? 1.0 : -1.0;
		vec.y = (diff.y > 0) ? 1.0 : -1.0;
		*size = ABS(diff.x);
	}
	else if (ABS(diff.x) > ABS(diff.y))
	{
		vec.x = (diff.x > 0) ? 1.0 : -1.0;
		vec.y = (double)((double)diff.y / (double)diff.x);
		*size = ABS(diff.x);
	}
	else if (ABS(diff.x) < ABS(diff.y))
	{
		vec.x = (double)((double)diff.x / (double)diff.y);
		vec.y = (diff.y > 0) ? 1.0 : -1.0;
		*size = ABS(diff.y);
	}
	return (vec);
}

void			draw_line(t_pos *pos1, t_pos *pos2, t_img **img)
{
	t_pos		point;
	t_vec		vec;
	int			size;
	int			i;

	i = 0;
	vec = get_vec(pos1, pos2, &size);
	point.x = pos1->x;
	point.y = pos1->y;
	while (i < size)
	{
		pixel_put_mlx(img, (int)vec.x, (int)vec.y);
		point.x += vec.x;
		point.y += vec.y;
		i++;
	}
}
