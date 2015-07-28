/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 18:39:02 by srison            #+#    #+#             */
/*   Updated: 2015/05/04 04:26:50 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void			put_pixel(int x, int y, t_mlx *mlx)
{
	char			*pixel;

	if ((x > mlx->w || x < 0) || (y > mlx->h || y < 0))
		return ;
	pixel = mlx->data + x * mlx->sl + (mlx->bpp / 8) * y;
	pixel[2] = (char)255;
	pixel[1] = (char)255;
	pixel[0] = (char)255;
}

static t_vec		get_vec(t_pos p1, t_pos p2)
{
	t_vec			result;
	t_pos			diff;
	t_pos			diff2;

	diff.x = p2.x - p1.x;
	diff.y = p2.y - p1.y;
	diff2.x = ABS(diff.x);
	diff2.y = ABS(diff.y);
	if (diff2.x < diff2.y)
	{
		result.x = diff2.y == 0 ? 1 : (double)diff.x / diff2.y;
		result.y = diff.y > 0 ? 1.0 : -1.0;
		result.iter = diff2.y;
	}
	else
	{
		result.y = diff2.x == 0 ? 1 : (double)diff.y / diff2.x;
		result.x = diff.x > 0 ? 1.0 : -1.0;
		result.iter = diff2.x;
	}
	return (result);
}

static void			draw_line_prev(t_pos pos, int **map, t_mlx *mlx, t_pos curr)
{
	t_pos			prev;
	t_vec			vec;
	double			x;
	double			y;
	int				i;

	i = -1;
	if (pos.y < 1)
		return ;
	prev.x = (pos.x * 20 - mlx->cste * map[pos.x][pos.y - 1]) / mlx->zoom +
		50 + mlx->pos_x;
	prev.y = ((pos.y - 1) * 20 - mlx->cste * map[pos.x][pos.y - 1] / 2) /
		mlx->zoom + 12 * pos.x / mlx->zoom + mlx->pos_y + 50;
	vec = get_vec(curr, prev);
	x = (double)curr.x;
	y = (double)curr.y;
	while (++i < vec.iter)
		if (x + i * vec.x > 0 && x + i * vec.x < mlx->w && y + i * vec.y > 0 &&
				y + i * vec.y < mlx->h)
			put_pixel(x + (i * vec.x), y + (i * vec.y), mlx);
}

static void			draw_line_top(t_pos pos, int **map, t_mlx *mlx, t_pos curr)
{
	t_pos			prev;
	t_vec			vec;
	double			x;
	double			y;
	int				i;

	i = -1;
	if (pos.x < 1)
		return ;
	prev.x = ((pos.x - 1) * 20 - mlx->cste * map[pos.x - 1][pos.y]) /
		mlx->zoom + 50 + mlx->pos_x;
	prev.y = (pos.y * 20 - mlx->cste * map[pos.x - 1][pos.y] / 2) / mlx->zoom +
		12 * (pos.x - 1) / mlx->zoom + mlx->pos_y + 50;
	vec = get_vec(curr, prev);
	x = (double)curr.x;
	y = (double)curr.y;
	while (++i < vec.iter)
		if (x + i * vec.x > 0 && x + i * vec.x < mlx->w && y + i * vec.y > 0 &&
			y + i * vec.y < mlx->h)
			put_pixel(x + (i * vec.x), y + (i * vec.y), mlx);
}

void				draw_calc(int **map, t_mlx *mlx)
{
	t_pos			pos;
	t_pos			curr;

	pos.x = -1;
	while (map[++(pos.x)])
	{
		pos.y = -1;
		while (map[pos.x][++(pos.y)] != END_LINE)
		{
			curr.x = (pos.x * 20 - mlx->cste * map[pos.x][pos.y]) / mlx->zoom +
				50 + mlx->pos_x;
			curr.y = (pos.y * 20 - mlx->cste * map[pos.x][pos.y] / 2) /
				mlx->zoom + 12 * pos.x / mlx->zoom + mlx->pos_y + 50;
			draw_line_top(pos, map, mlx, curr);
			draw_line_prev(pos, map, mlx, curr);
		}
	}
}
