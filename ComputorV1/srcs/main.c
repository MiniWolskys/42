/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:01:11 by srison            #+#    #+#             */
/*   Updated: 2015/06/14 16:01:42 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include "libft.h"
#include <stdio.h>

static int		check_calc(char *calc)
{
	int			i;

	i = -1;
	while (calc[++i])
		if (calc[i] != ' ' && calc[i] != 'X' && calc[i] != '^' && calc[i] != '='
			&& calc[i] != '+' && calc[i] != '-' && !ft_isdigit(calc[i]) &&
			calc[i] != '.' && calc[i] != ',' && calc[i] != '*')
		{
			printf("This character is not correct : %c.\n", calc[i]);
			return (0);
		}
	return (1);
}

static void		print_simplified(double *value, char *calc)
{
	int			max;

	max = get_size(calc);
	printf("simplified form :\n");
	while (max)
	{
		if (value[max] < -0.0001)
			printf(" - %.3f", -value[max]);
		else if (value[max] > 000.1)
			printf(" + %.3f", value[max]);
		if (!(max - 1) && (value[max] > 0.0001 || value[max] < -0.0001))
			printf("X");
		else if ((max - 1) != 0 && (value[max] > 00.001 || value[max] < -0.001))
			printf("X^%d", max);
		max--;
	}
	if (value[0] > 0.0001)
		printf(" + %.3f", value[0]);
	else if (value[0] < -0.0001)
		printf(" - %.3f", -value[0]);
	else if (!check_value(get_size(calc), value, 1))
		printf("0");
	printf(" = 0\n");
}

int				main(int ac, char **av)
{
	double		*value;

	if (ac != 2)
	{
		ft_putendl("Error : It should be :\n./computor [equation]");
		return (1);
	}
	if (!check_calc(av[1]))
	{
		ft_putendl("Error : Equation invalid");
		return (1);
	}
	if (!(value = get_equation(av[1])))
	{
		ft_putendl("Error resolving the equation.");
		return (1);
	}
	print_simplified(value, av[1]);
	if (get_size(av[1]) > 2 && check_value(get_size(av[1]), value, 3))
	{
		ft_putendl("Can't solve an equation with a degree greater than 2.");
		return (1);
	}
	resolve(value, get_size(av[1]));
	return (0);
}
