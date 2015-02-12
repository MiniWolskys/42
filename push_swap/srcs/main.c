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

static int			get_value(char *str)
{
	int		j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] <= '9' && str[j] >= '0')
		j++;
	if (str[j])
		return (ERROR);
	return (ft_atoi(str));
}

static int			get_size(char **tab)
{
	int			result;

	result = 0;
	while (tab[result])
		result++;
	return (result);
}

static t_struct		*get_first_pile(char **tab)
{
	t_struct		*a;
	t_struct		*final;
	int				i;
	int				pos;

	i = 0;
	pos = get_size(tab);
	if (!(a = ((t_struct *)ft_memalloc(sizeof(*a)))))
		return (NULL);
	final = a;
	while (tab[++i])
	{
		if (!(final->next = (t_struct *)ft_memalloc(sizeof(*final))))
			return (NULL);
		final = final->next;
		if (!(final->value = get_value(tab[i])) == ERROR)
			return (NULL);
		final->pos = pos;
		final->next = NULL;
		pos--;
	}
	final = a->next;
	free(a);
	return (final);
}

int					main(int ac, char **av)
{
	t_struct		*a;
	t_struct		*b;

	if (ac >= 2)
	{
		b = NULL;
		if (!(a = get_first_pile(av)))
		{
			ft_putstr("\n");
			return (0);
		}
		while (a->next)
			push_swap(&a, &b);
		while (b)
		{
			push_a(&a, &b);
			if (b)
				ft_putchar(' ');
		}
		ft_putstr("\b\n");
	}
	else
		ft_putchar('\n');
	return (1);
}
