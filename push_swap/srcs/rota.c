/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 23:04:31 by srison            #+#    #+#             */
/*   Updated: 2015/02/09 23:04:32 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			rota(t_struct **lst)
{
	t_struct		*tmp;
	t_struct		*mem;
	int				prev_value;
	int				swap;

	tmp = *lst;
	if (!tmp)
		return ;
	mem = tmp;
	while (mem->next)
		mem = mem->next;
	prev_value = tmp->value;
	tmp->value = mem->value;
	while (tmp)
	{
		swap = tmp->value;
		tmp->value = prev_value;
		prev_value = swap;
		tmp = tmp->next;
	}
}

void				rota_a(t_struct **lst)
{
	rota(lst);
	ft_putstr("ra ");
}
