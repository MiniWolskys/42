/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:14:10 by srison            #+#    #+#             */
/*   Updated: 2014/11/10 13:42:03 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_negat(char *nbr, int *sign, int *i)
{
	if (nbr[*i] == '-')
	{
		if (nbr[(*i) + 1] == '+')
			return (0);
		(*sign) = -1;
		(*i)++;
	}
	if (nbr[*i] == '+')
	{
		if (nbr[(*i) + 1] == '-')
			return (0);
		(*i)++;
	}
	return (1);
}

int			ft_atoi(char *nbr)
{
	int		result;
	int		i;
	int		is_negatif;

	i = 0;
	result = 0;
	is_negatif = 1;
	while (nbr[i] != '-' && nbr[i] != '+' && (nbr[i] < '0' || nbr[i] > '9'))
	{
		if ((nbr[i] == '\200') || (nbr[i] >= 'a' && nbr[i] <= 'z') ||
			(nbr[i] >= 'A' && nbr[i] <= 'Z'))
			return (0);
		i++;
	}
	if (!(get_negat(nbr, &is_negatif, &i)))
		return (0);
	while (nbr[i])
	{
		if (nbr[i] >= '0' && nbr[i] <= '9')
			result = 10 * result + ((nbr[i]) - '0');
		else
			return (result * is_negatif);
		i++;
	}
	return (result * is_negatif);
}
