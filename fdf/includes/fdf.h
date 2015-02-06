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

# define ABS(x) ((x) < 0 ? (-x) : (x))

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;
typedef struct s_vec	t_vec;

struct					s_vec
{
	double				x;
	double				y;
};

struct					s_img
{
	void				*img_ptr;
	char				*data;
	int					size_line;
	int					endian;
	int					bpp;
	int					zoom;
	unsigned int		color;
};

struct					s_mlx
{
	t_img				*struct_img;
	void				*mlx_ptr;
	void				*win_ptr;
	t_pos				*img_pos_win;
};

int						**get_map(char *file, t_pos **size);
int						init_mlx_struct(t_mlx **mlx_struct);
int						read_map(t_mlx **mlx_struct, int **map, t_pos *size);
int						get_event(t_mlx *mlx_struct/*, int **map, t_pos *size*/);
void					get_pos(t_pos **value, int **map, t_pos pos, t_img **img);
void					draw_line(t_pos *pos1, t_pos *pos2, t_img **img);

#endif
