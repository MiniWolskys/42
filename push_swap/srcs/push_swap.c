/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:21:16 by srison            #+#    #+#             */
/*   Updated: 2015/02/09 17:21:21 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_struct **start_a, t_struct **start_b)
{
	t_struct		*a;
	int				max;
	int				pos;

	a = *start_a;
	max = a->value;
	pos = a->pos;
	while (a)
	{
		if (a->value > max)
		{
			max = a->value;
			pos = a->pos;
		}
		a = a->next;
	}
	if (pos == 2)
		swap_a(start_a);
	if (pos >= 2)
		push_b(start_a, start_b);
	else
		rota_a(start_a);
}
