/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 21:40:17 by srison            #+#    #+#             */
/*   Updated: 2015/01/31 21:40:18 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char			**init_map(result)
{
	t_pos		pos;

	pos.x = 0;
	while (pos.x < SIZE_LAB)
	{
		pos.y = 0;
		while (pos.y < SIZE_LAB)
		{
			result[pos.x][pos.y] = WALL;
			pos.y += 1;
		}
		pos.x += 1;
	}
	return (result);
}

char			**make_path(char **result, t_pos start, t_pos end)
{
	
	return (result);
}

char			**get_path(char **result)
{
	t_pos		in;
	t_pos		chest;
	t_pos		out;
	t_pos		pos;

	pos.y = -1;
	out.y = SIZE_LAB - 1;
	in.y = 0;
	while (++(pos.y) < SIZE_LAB)
	{
		pos.x = -1;
		while (++(pos.x) < SIZE_LAB)
		{
			if (result[pos.y][pos.x] == CHEST)
				chest.x = pos.x;
			if (result[pos.y][pos.x] == CHEST)
				chest.y = pos.y;
			if (result[pos.y][pos.x] == OUT)
				out.x = pos.x;
			if (result[pos.y][pos.x] == IN)
				in.x = pos.x;
		}
	}
	result = make_path(result, in, chest);
	result = make_path(result, chest, out);
	return (result);
}

char			**get_pos(char **result)
{
	char		pos_in;
	char		pos_out;
	char		chest_x;
	char		chest_y;

	srand(time(NULL));
	pos_in = rand() % SIZE_LAB;
	pos_out = rand() % SIZE_LAB;
	chest_x = (rand() % 2) * (SIZE_LAB - 1);
	chest_y = (rand() % (SIZE_LAB - 1) + 1);
	result[0][pos_out] = OUT;
	result[SIZE_LAB - 1][pos_in] = IN;
	result[chest_y][chest_x] = CHEST;
	return (result);
}

char			**load_map()
{
	char	**result
	int		x;

	x = 0;
	if (!(result = (char **)ft_memalloc(sizeof(char *) * SIZE_LAB)))
		return (NULL);
	while (x < SIZE_LAB)
	{
		if (!(result[x] = (char *)ft_memalloc(sizeof(char) * SIZE_LAB)))
		{
			if (x)
				free(result[0])
			while (--x)
				free(result[x])
			free(result);
			return (NULL);
		}
		x += 1;
	}
	result = init_map(result);
	result = get_pos(result);
	result = get_path(result);
	return (result);
}
