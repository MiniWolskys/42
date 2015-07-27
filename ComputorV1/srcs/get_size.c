/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:49:24 by srison            #+#    #+#             */
/*   Updated: 2015/06/10 14:50:24 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_size(char *calc)
{
	int		max;
	int		i;

	max = 0;
	i = -1;
	while (calc[++i])
	{
		if (ft_isdigit(calc[i]) && i && calc[i - 1] == '^' &&
			calc[i] - '0' > max)
			max = calc[i] - '0';
		else if (ft_isdigit && !max)
			max = 1;
	}
	return (max);
}
