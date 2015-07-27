/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 01:34:35 by srison            #+#    #+#             */
/*   Updated: 2015/07/02 01:34:36 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H

# define WOLF_H

# define VERBOSE 1
# define SCREEN_SIZE 1200

# include "libft.h"

typedef struct	s_mlx
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	t_vec		pos;
	float		pos_z;
	int			dir;
	int			m_x;
	int			bpp;
	int			sl;
}				t_mlx;

t_mlx			*boot();
float			get_wall_distance(int angle, t_vec pt_cam, char **map);
void			manage_event(t_mlx *mlx);
void			img_pixel_put(t_mlx *mlx, int x, int y, int color);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
int				draw(t_mlx *mlx, t_vec pt_cam);
void			clear_image(t_mlx *mlx);

#endif
