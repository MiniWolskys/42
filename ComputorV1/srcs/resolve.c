/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:17:45 by srison            #+#    #+#             */
/*   Updated: 2015/06/13 16:26:57 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include "libft.h"
#include <stdio.h>

int				check_value(int max, double *value, int limit)
{
	while (max >= limit)
	{
		if (value[max] > 0.0001 || value[max] < -0.0001)
			return (1);
		max--;
	}
	return (0);
}

static void		get_two(double *value)
{
	float		delta;

	delta = (value[1] * value[1]) - 4.0 * (value[0] * value[2]);
	printf("Delta value is :\n%.3f\n", delta);
	if (delta < -0.0001)
	{
		printf("Delta is less than 0. There are two complex solutions.\n");
		printf("X = %.3f + i * %.3f.\n", -value[1] / (2.0 * value[2]),
			ft_square_root(ABS(delta), 3) / (2.0 * value[2]));
		printf("or X = %.3f - i * %.3f.\n", -value[1] / (2.0 * value[2]),
			ft_square_root(ABS(delta), 3) / (2.0 * value[2]));
	}
	else if (delta < 0.0001 && delta > -0.0001)
	{
		printf("Delta value is 0, so there is one and only one solution :\n");
		printf("X = %.3f.\n", (-value[1] / 2.0 * value[2]));
	}
	else
	{
		printf("Delta is greater than 0. There are two solutions :\n");
		printf("X = %.3f.\n", (-value[1] + ft_square_root(delta, 3)) /
			(2.0 * value[2]));
		printf("or X = %.3f.\n", (-value[1] - ft_square_root(delta, 3)) /
			(2.0 * value[2]));
	}
}

void			resolve(double *value, int max)
{
	if (max == 0 || !check_value(max, value, 1))
	{
		if (value[0] > -0.0001 && value[0] < 0.0001)
			printf("All X value are solutions\n");
		else
			printf("No solution for this equation.\n");
	}
	else if (max == 1 || !check_value(max, value, 2))
		printf("The solution is %.3f.\n", (float)(-value[0] / value[1]));
	else if (max == 2 || !check_value(max, value, 3))
		get_two(value);
}
