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

# define ABS(x) (x > 0) ? x : -x
# define MLX_HEIGHT 1000
# define MLX_WIDTH 1000

typedef struct		s_vec
{
	double			x;
	double			y;
	int				iter;
}					t_vec;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				**map;
	double			zoom;
	double			cste;
	int				size_x;
	int				size_y;
	int				endian;
	int				pos_x;
	int				pos_y;
	int				bpp;
	int				sl;
	int				w;
	int				h;
}					t_mlx;

int					check_file(char **file);
int					use_mlx(t_mlx *mlx);
void				draw_calc(int **map, t_mlx *mlx);

#endif
