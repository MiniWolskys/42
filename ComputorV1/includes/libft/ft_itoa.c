/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:49:26 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 16:41:31 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoaisnegative(int *n, int *is_negative, int *count)
{
	if (*n < 0)
	{
		*n *= -1;
		*is_negative = 1;
		*count = *count + 1;
	}
	return ;
}

static int	ft_itoa_getsize(int n, int count)
{
	int		cnt;

	cnt = 1;
	while (cnt <= n)
	{
		cnt *= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		count;
	int		is_negative;

	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	is_negative = 0;
	count = 0;
	ft_itoaisnegative(&n, &is_negative, &count);
	count = ft_itoa_getsize(n, count);
	nbr = ft_strnew(count);
	if (is_negative)
		nbr[0] = '-';
	while (count > is_negative)
	{
		nbr[count - 1] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	return (nbr);
}
