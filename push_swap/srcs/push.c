/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:59:22 by srison            #+#    #+#             */
/*   Updated: 2015/02/05 17:59:23 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push(t_struct **out, t_struct **in)
{
	t_struct		*tmp;
	t_struct		*tmp_out;

	tmp = *out;
	tmp_out = (*out)->next;
	tmp->next = *in;
	in = &tmp;
	out = &tmp_out;
	while (tmp)
	{
		(tmp->pos)++;
		tmp = tmp->next;
	}
	while (tmp_out)
	{
		(tmp_out->pos)++;
		tmp_out = tmp_out->next;
	}
}

void			push_a(t_struct **a, t_struct **b)
{
	push(b, a);
	ft_putstr("pa");
}

void			push_b(t_struct **a, t_struct **b)
{
	push(a, b);
	ft_putstr("pb");
}
