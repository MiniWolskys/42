/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 12:33:27 by srison            #+#    #+#             */
/*   Updated: 2015/01/07 11:42:40 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"


typedef struct s_mlx	t_mlx;
typedef struct s_pos	t_pos;
typedef struct s_line	t_line;

struct					s_mlx
{
	void				*mlx;
	void				*win;
};

int						print_map(int **map, t_mlx e);
void					get_pos(int x, int y, int z, t_pos **value);
int						draw_line_top(t_pos pos, int **map,
							t_pos *curr, t_mlx e);
int						draw_line_prev(t_pos *curr, t_pos *prev, t_mlx e);

#endif
