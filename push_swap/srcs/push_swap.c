/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:50:46 by srison            #+#    #+#             */
/*   Updated: 2015/02/05 13:50:47 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_swap(t_struct **a, t_struct **b)
{
	t_struct	*tmp;
	int			max;
	int			pos;

	max = (*a)->value;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (pos == 2)
		swap_a(a);
	if (pos <= 2)
		push_b(a, b);
	else
		rota_a(a);
}
