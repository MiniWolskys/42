/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:54:31 by srison            #+#    #+#             */
/*   Updated: 2015/01/23 00:54:32 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pos(t_pos **value, int **map, t_pos pos, t_img **img)
{
	(*value)->x = (*img)->zoom * pos.x + pos.x * 10 + 20 * pos.y + 10;
	(*value)->y = (*img)->zoom * pos.y + 10 + 30 * pos.x + 2 * map[pos.y][pos.x];
}
