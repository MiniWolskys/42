/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_equation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:10:03 by srison            #+#    #+#             */
/*   Updated: 2015/06/14 16:01:40 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "computor.h"

static double	get_value(char *op)
{
	double		value;

	value = 0;
	if (!(value = ft_atof(op)) && op[0] != '0')
		value++;
	return (value);
}

static int		get_pos(char *op)
{
	int			i;

	i = -1;
	while (op[++i])
	{
		if (i && (op[i] == '+' || op[i] == '-'))
			return (0);
		if (op[i] == 'X')
		{
			if (op[i + 1] == '^')
				return (op[i + 2] - '0');
			return (1);
		}
	}
	return (0);
}

static double	*get_second(char *part, double *value)
{
	int			i;

	if (!part)
		return (value);
	i = -1;
	while (part[++i])
		if (part[i] == '+' || part[i] == '-' || !i)
			value[get_pos(&(part[i]))] -= get_value(&(part[i]));
	return (value);
}

static double	*get_first(char **both_side, int max)
{
	double		*value;
	int			i;

	if (!(value = (double *)ft_memalloc(sizeof(*value) * (max + 1))))
		return (NULL);
	i = -1;
	while (++i <= max)
		value[i] = 0.0;
	i = -1;
	while (both_side[0][++i])
		if (!i || both_side[0][i] == '+' || both_side[0][i] == '-')
			value[get_pos(&(both_side[0][i]))] += get_value(&(both_side[0][i]));
	return (get_second(both_side[1], value));
}

double			*get_equation(char *calc)
{
	char		**both_side;
	char		*mem;
	int			max;

	if (!(mem = ft_strdelchar(calc, ' ')))
		return (NULL);
	if (!(calc = ft_strdelchar(mem, '\t')))
		return (NULL);
	max = get_size(calc);
	if (!(both_side = ft_strsplit(calc, '=')))
		return (NULL);
	return (get_first(both_side, max));
}
