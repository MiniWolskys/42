/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 00:13:17 by srison            #+#    #+#             */
/*   Updated: 2015/02/10 00:13:18 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		change_pos(t_struct **out, t_struct **in)
{
	t_struct		*tmp;
	t_struct		*mem;

	tmp = *out;
	mem = *in;
	while (tmp)
	{
		tmp->pos -= 1;
		tmp = tmp->next;
	}
	while (mem)
	{
		mem->pos += 1;
		mem = mem->next;
	}
}

static void		push(t_struct **out, t_struct **in)
{
	t_struct		*tmp;
	t_struct		*mem;

	tmp = *out;
	while (tmp->next && tmp->next->next)
	{
		tmp->pos -= 1;
		tmp = tmp->next;
	}
	mem = *in;
	while (mem->next)
		mem = mem->next;
	if (!tmp->next)
	{
		mem->next = tmp;
		*out = NULL;
	}
	else
	{
		mem->next = tmp->next;
		tmp->next = NULL;
	}
	change_pos(out, in);
}

void			push_a(t_struct **a, t_struct **b)
{
	push(b, a);
	ft_putstr("pa ");
}

void			push_b(t_struct **a, t_struct **b)
{
	push(a, b);
	ft_putstr("pb ");
}
