/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 10:24:52 by srison            #+#    #+#             */
/*   Updated: 2015/01/15 10:24:55 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_line(t_pos *pt1, t_pos *pt2, t_mlx e)
{
	t_pos	coef;
	t_pos	lim;
	float	x;
	float	y;

	coef.x = (pt2->x >= pt1->x) ? pt2->x - pt1->x : pt1->x - pt2->x;
	coef.y = (pt2->y >= pt1->y) ? pt2->y - pt1->y : pt1->y - pt2->y;
	coef.x = (coef.x == 0) ? 1 : coef.x;
	coef.y = (coef.y == 0) ? 1 : coef.y;
	x = (pt2->x >= pt1->x) ? pt1->x : pt2->x;
	y = (pt2->y >= pt1->y) ? pt1->y : pt2->y;
	lim.x = (pt2->x > pt1->x) ? pt2->x : pt1->x;
	lim.y = (pt2->y > pt1->y) ? pt2->y : pt1->y;
	while (x < lim.x || y < lim.y)
	{
		x += (coef.x >= coef.y) ? 1 : (float)((float)coef.x / (float)coef.y);
		y += (coef.x <= coef.y) ? 1 : (float)((float)coef.y / (float)coef.x);
		mlx_pixel_put(e.mlx, e.win, x, y, 0xFFFFFF);
	}
	return (1);
}

int			draw_line_prev(t_pos *curr, t_pos *prev, t_mlx e)
{
	if (!prev)
		return (1);
	if (prev->x < curr->x)
		ft_swap((void **)&prev, (void **)&curr);
	if (!(draw_line(curr, prev, e)))
		return (0);
	return (1);
}

int			draw_line_top(t_pos pos, int **map, t_pos *curr, t_mlx e)
{
	t_pos	*top;
	int		x;

	if (pos.x == 0)
		return (1);
	x = 0;
	while (x <= pos.y)
	{
		if (map[pos.x - 1][x] == END_LINE)
			return (1);
		x++;
	}
	if (!(top = (t_pos *)ft_memalloc(sizeof(*top))))
		return (0);
	get_pos(pos.x - 1, pos.y, map[pos.x - 1][pos.y], &top);
	if (top->x < curr->x)
		ft_swap((void **)&top, (void **)&curr);
	if (!(draw_line(curr, top, e)))
		return (0);
//	if (top)
//		free(top);
	return (1);
}
