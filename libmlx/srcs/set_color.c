/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 07:38:36 by srison            #+#    #+#             */
/*   Updated: 2015/01/07 10:10:20 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int		set_color(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red >> 16, green >> 8, blue);
}
