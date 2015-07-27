/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:28:45 by srison            #+#    #+#             */
/*   Updated: 2014/12/29 07:17:42 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_set_color(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 8 | green << 16 | blue << 24);
}
