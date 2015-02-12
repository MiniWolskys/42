/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 22:05:14 by srison            #+#    #+#             */
/*   Updated: 2015/02/09 22:05:15 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(t_struct **lst)
{
	t_struct		*tmp;
	int				value;

	tmp = *lst;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (!tmp || !tmp->next)
		return ;
	value = tmp->next->value;
	tmp->next->value = tmp->value;
	tmp->value = value;
}

void			swap_a(t_struct **lst)
{
	swap(lst);
	ft_putstr("sa ");
}
