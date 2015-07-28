/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:02:28 by srison            #+#    #+#             */
/*   Updated: 2014/11/12 14:24:50 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int		sign;

	sign = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr((nb / 10) * sign);
		ft_putnbr((nb % 10) * sign);
	}
	else
		ft_putchar((nb * sign) + '0');
	return ;
}
