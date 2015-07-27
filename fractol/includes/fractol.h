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

# define FRACTOL_H

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000
# define MAX 40

typedef struct s_mlx	t_mlx;
typedef struct s_vec	t_vec;

struct					s_vec
{
	double				x;
	double				y;
};

struct					s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	double				zoom;
	int					**map;
	int					fractal;
	int					iter;
	int					bpp;
	int					set;
	int					sl;
	int					y;
	int					x;
	int					w;
	int					h;
};

int						set_color(unsigned char red, unsigned char green,
						unsigned char blue);
void					img_pixel_put(t_mlx *mlx, int x, int y, int color);
void					get_event(t_mlx *mlx);
void					draw_mandel(t_mlx *mlx);
void					draw_julia(t_mlx *mlx);
void					draw_ship(t_mlx *mlx);
void					reset_image(t_mlx *mlx);
void					redraw_mlx(t_mlx *mlx);
int						mouse_hook(int buttonpress, int x, int y, t_mlx *mlx);
// int					mouse_move(int x, int y, t_mlx *mlx);

#endif
