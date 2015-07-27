/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 22:45:11 by srison            #+#    #+#             */
/*   Updated: 2015/06/03 05:51:24 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(char *str)
{
	float		result;
	int			sign;
	int			mult;
	int			i;

	result = (float)ft_atoi(str);
	i = 0;
	sign = 1;
	if (str[0] == '-' || str[i] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] != '.' && str[i] != ','))
		i++;
	if (str[i] == '\0')
		return (result);
	mult = 10;
	while (str[++i] && ft_isdigit(str[i]))
	{
		result += (float)((float)(str[i] - 48.0) / (float)mult);
		mult *= 10;
	}
	return (result);
}
