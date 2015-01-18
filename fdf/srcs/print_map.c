/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 07:40:43 by srison            #+#    #+#             */
/*   Updated: 2015/01/09 04:10:57 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				print_map(int **map, t_mlx e)
{
	t_pos	current;
	t_pos	*curr;
	t_pos	*prev;

	current.x = -1;
	while (map[++(current.x)])
	{
		current.y = -1;
		prev = NULL;
		while (map[current.x][++(current.y)] != END_LINE)
		{
			if (!(curr = (t_pos *)ft_memalloc(sizeof(*curr))))
				return (0);
			get_pos(current.x, current.y, map[current.x][current.y], &curr);
			if (!(draw_line_prev(curr, prev, e)) || !(draw_line_top(current, map, curr, e)))
				return (0);
			if (prev)
				free(prev);
			prev = curr;
		}
	}
	return (1);
}
