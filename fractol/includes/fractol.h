/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:02:27 by srison            #+#    #+#             */
/*   Updated: 2015/01/02 00:56:11 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_mlx	t_mlx;

struct					s_mlx
{
	void				*mlx;
	void				**win;
};

typedef struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

int						set_color(unsigned char red, unsigned char green,
						unsigned char blue);


#endif
