/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 21:23:35 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 18:11:26 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	int		index;

	if (!(tab))
		return ;
	index = 0;
	while (tab[index])
	{
		ft_putendl(tab[index]);
		index++;
	}
	return ;
}
