/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 15:51:48 by srison            #+#    #+#             */
/*   Updated: 2015/01/15 15:51:50 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pos(int x, int y, int z, t_pos **value)
{
	(*value)->x = 10 * x + 20 * y + 10;
	(*value)->y = 10 + 30 * x + 2 * (-z);
}
