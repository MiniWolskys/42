/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:50:37 by srison            #+#    #+#             */
/*   Updated: 2015/02/05 13:50:39 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_struct		*get_first_pile(char **tab)
{
	t_struct		*lst;
	t_struct		*tmp;
	int				i;
	int				j;
	int				pos;

	i = -1;
	pos = 1;
	if (!(lst = (t_struct *)ft_memalloc(sizeof(*lst))))
		return (NULL);
	tmp = lst;
	while (tab[++i])
	{
		tmp = tmp->next;
		j = -1;
		while (tab[i][++j])
			if (j != '+' && j != '-' && (j < '0' || j > '9'))
				return (NULL);
		tmp->value = ft_atoi(tab[i]);
		tmp->pos = pos;
		if (!(tmp->next = (t_struct *)ft_memalloc(sizeof(*lst))))
			return (NULL);
		pos++;
	}
	free(tmp->next);
	tmp->next = NULL;
	tmp = lst->next;
	free(lst);
	return (tmp);
}

//	get_first_pile a refaire

int					main(int ac, char **av)
{
	t_struct		*a;
	t_struct		*b;

	if (ac >= 2)
	{
		b = NULL;
		if (!(a = get_first_pile(av)))
			return (0);
		while (a->next)
			push_swap(&a, &b);
		while (b)
		{
			push_a(&a, &b);
			b = b->next;
		}
	}
	ft_putchar('\n');
	return (1);
}
