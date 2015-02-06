/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:59:29 by srison            #+#    #+#             */
/*   Updated: 2015/02/05 17:59:30 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		rota(t_struct **lst)
{
	t_struct		*tmp;
	t_struct		*temp;
	int				i;

	tmp = (*lst)->next;
	i = 1;
	temp = *lst;
	while (tmp->next)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
	lst = &(temp->next);
	tmp->next = temp;
	temp->next = NULL;
}

void			rota_a(t_struct **a)
{
	rota(a);
	ft_putstr("ra");
}
