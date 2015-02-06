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

int		ft_atoi(char *nbr)
{
	int		result;
	int		i;
	int		is_negatif;

	i = 0;
	result = 0;
	is_negatif = 1;
	if (nbr[i] == '-')
	{
		is_negatif = -1;
		i = 1;
	}
	if (nbr[0] == '+')
		i++;
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
