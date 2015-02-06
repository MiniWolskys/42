/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:12:47 by srison            #+#    #+#             */
/*   Updated: 2015/01/02 00:56:09 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_parameters_error()
{
	ft_putendl("Error : Not enough arguments.");
	ft_putendl("Usage :");
	ft_putendl("./fractol [fractal1 type, datas] [fractal2 type, datas]...");
	return (1);
}

static int	get_printable(t_mlx *e, char *datas, void *fct_ptr)
{
	char	*name;
	char	*data;
	int		i;

	if (!(name = ft_strshr(datas, ',')))
			return (0);
	if ((data = ft_strchr(data, ',')))
		if (!(data = ft_strdup(data)))
			return (0);
	if (!(ft_strcmp(name, "Julia")))
		i = 1;
	else if (!(ft_strcmp(name, "Mandelbrot")))
		i = 0;
	else if (!(ft_strcmp(name, "Coquillageant")))
		i = 2;
	else
		return (0);
	if (!(e->win = (void **)ft_realloc(sizeof(e->win) + sizeof(void *))))
		return (0);
	e->win[sizeof(e->win) - sizeof(void *)] = (fct_ptr[i])(e->mlx, data);
	return (1);
}

static void	*set_array_fct(void *(*fct_ptr)(void *mlx, char *data))
{
	if (!(fct_ptr = ft_memalloc(sizeof(*fct_ptr) * 4)))
		return (NULL);
	fct_ptr[0] = &draw_mandelbrot;
	fct_ptr[1] = &draw_julia;
	fct_ptr[2] = &draw_coquillageant;
	return (fct_ptr);
}

int			main(int ac, char **av)
{
	int		i;
	t_mlx	*e;
	void	*(*fct_ptr)(void *mlx, char *data);

	if (ac < 2)
		return (put_parameters_error());
	if (!(fct_ptr = set_array_fct(fct_ptr)))
		return (1);
	if (!(e = (t_mlx *)ft_memalloc(sizeof(*e))))
		return (1);
	e->mlx = mlx_init;
	e->win = NULL;
	i = 0;
	while (++i < ac)
	{
		if (!(get_printable(e, av[i], fct_ptr)))
		{
			av++;
			ac--;
		}
	}
	get_event(lst);
	return (0);
}
