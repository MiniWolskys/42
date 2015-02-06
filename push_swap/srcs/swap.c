/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:59:36 by srison            #+#    #+#             */
/*   Updated: 2015/02/05 17:59:37 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(t_struct **lst)
{
	int		tmp;

	tmp = (*lst)->next->value;
	(*lst)->next->value = (*lst)->value;
	(*lst)->value = tmp;
}

void			swap_a(t_struct **a)
{
	swap(a);
	ft_putstr("sa");
}
