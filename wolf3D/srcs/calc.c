/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 06:57:10 by srison            #+#    #+#             */
/*   Updated: 2015/07/09 06:57:11 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

static t_vec	get_wall(t_vec pt_wall, t_vec vec, char **map)
{
	t_vec		tmp;

	tmp.x = pt_wall.x + vec.x;
	tmp.y = pt_wall.y - vec.y;
	if (map[(int)tmp.x][(int)pt_wall.y] != '0')
	{
		pt_wall.y += vec.y * (tmp.x - (int)tmp.x) / vec.x;
		pt_wall.x = (int)tmp.x;
	}
	else if (map[(int)pt_wall.x][(int)tmp.y] != '0')
	{
		pt_wall.x += vec.x * (tmp.y - (int)tmp.y) / vec.y;
		pt_wall.y = (int)tmp.y;
	}
	else
	{
		pt_wall.x = tmp.x;
		pt_wall.y = tmp.y;
	}
	return (pt_wall);
}

static float	get_length(char **map, t_vec vec, t_vec pt_cam)
{
	float		length;
	t_vec		pt_wall;

	pt_wall.x = pt_cam.x;
	pt_wall.y = pt_cam.y;
	while (!(map[(int)pt_wall.x][(int)pt_wall.y] - '0'))
		pt_wall = get_wall(pt_wall, vec, map);
	length = sqrt(pow(pt_cam.x - pt_wall.x, 2) + pow(pt_cam.y - pt_wall.y, 2));
	return (length);
}

static t_vec	get_vec_from_angle(int angle)
{
	t_vec		vec;

	vec.y = angle <= 180 ? (angle - 90) / 90.0 : (angle - 270) / (-270.0);
	if (angle < 90)
		vec.x = angle / -90.0;
	else if (angle > 270)
		vec.x = (angle - 270) / 90.0;
	else
		vec.x = (angle - 180) / 90.0;
	return (vec);
}

float			get_wall_distance(int angle, t_vec pt_cam, char **map)
{
	t_vec		vec;
	float		length;
	int			x;

	vec = get_vec_from_angle(angle);
	x = -1;
	while (map[++x])
	{
		map[x] = ft_strdelchar(map[x], ' ');
		map[x] = ft_strdelchar(map[x], ',');
	}
	length = get_length(map, vec, pt_cam);
	return (length);
}
