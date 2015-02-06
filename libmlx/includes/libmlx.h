/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 13:52:48 by srison            #+#    #+#             */
/*   Updated: 2015/01/25 13:53:03 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBMLX_H

# define LIBMLX_H

# include "libft.h"

typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;

struct					s_img
{
	void				*img_ptr;
	int					*data;
	size_t				img_height;
	size_t				img_width;
};

struct					s_mlx
{
	t_img				*img_struct;
	void				*mlx_ptr;
	void				*win_ptr;
	size_t				win_height;
	size_t				win_width;
	size_t				pos_height;
	size_t				pos_width;
};

#endif
