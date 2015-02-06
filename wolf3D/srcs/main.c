/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:15:04 by srison            #+#    #+#             */
/*   Updated: 2015/01/31 18:15:04 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main()
{
	char		**map;
//	t_mlx		*mlx;

	if (!(map = load_map()))
		return (0);
	if (map)
		return (1);
//	if (!(mlx = init_mlx(1000, 1000, "Wolf.42.srison", 1)))
//		return (0);
//	if (!(start_game(map, mlx)))
//		return (0);
	return (1);
}
