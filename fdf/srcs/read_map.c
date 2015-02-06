/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 10:01:12 by srison            #+#    #+#             */
/*   Updated: 2015/01/22 10:01:13 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_top(int **map, t_pos pos, t_pos *curr, t_img **img)
{
	t_pos	*top;
	t_pos	new_pos;

	if (pos.y < 1 || map[pos.y - 1][pos.x] == END_LINE)
		return (1);
	new_pos.x = pos.x;
	new_pos.y = pos.y - 1;
	if (!(top = (t_pos *)ft_memalloc(sizeof(*top))))
		return (0);
	get_pos(&top, map, new_pos, img);
	draw_line(curr, top, img);
	return (1);
}

static int		get_img(t_img **img, int **map, t_pos *size)
{
	t_pos	pos;
	t_pos	*curr;
	t_pos	*prev;

	pos.y = -1;
	while (++(pos.y) < size->y)
	{
		pos.x = -1;
		prev = NULL;
		while (++(pos.x) < size->x && map[pos.y][pos.x] != END_LINE)
		{
			if (!(curr = (t_pos *)ft_memalloc(sizeof(*curr))))
				return (0);
			get_pos(&curr, map, pos, img);
			draw_line(curr, prev, img);
			if (!(get_top(map, pos, curr, img)))
				return (0);
			if (prev)
				free(prev);
			prev = curr;
		}
	}
	return (1);
}

int				read_map(t_mlx **mlx_struct, int **map, t_pos *size)
{
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(*img))))
		return (0);
	if (!(img->img_ptr = mlx_new_image((*mlx_struct)->mlx_ptr, 500, 500)))
		return (0);
	if (!(img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_line), &(img->endian))))
		return (0);
	if (!(get_img(&img, map, size)))
		return (0);
	(*mlx_struct)->struct_img = img;
	return (1);
}
