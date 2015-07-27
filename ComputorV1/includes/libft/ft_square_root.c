/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 10:28:55 by srison            #+#    #+#             */
/*   Updated: 2015/06/13 16:28:45 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

float			ft_square_root(float nbr, int prec)
{
	float		value;
	int			n;
	int			i;

	i = -1;
	value = 0;
	n = 1;
	while (++i <= prec + 1 && n < 100000)
	{
		while (value * value < nbr)
			value += (float)(1.0 / n);
		if (value * value == nbr)
			return (value);
		value -= (float)(1.0 / n);
		n *= 10;
	}
	return (value);
}
