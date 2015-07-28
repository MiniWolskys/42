/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnewl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:37:54 by srison            #+#    #+#             */
/*   Updated: 2014/11/26 07:37:57 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnewl(char const *s)
{
	ft_putchar('\n');
	if (s)
		ft_putstr(s);
	ft_putchar('\n');
	return ;
}