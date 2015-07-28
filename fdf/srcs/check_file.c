/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 08:25:38 by srison            #+#    #+#             */
/*   Updated: 2015/04/28 08:25:44 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			put_file_error(int error, char c)
{
	if (error == 1)
	{
		ft_putstr("Invalid value for the map : \"");
		ft_putchar(c);
		ft_putendl("\".");
	}
	else if (error == 2)
		ft_putendl("Lines are not well formated (different size).");
	else if (error == 3)
		ft_putendl("Empty file.");
	else if (error == 4)
		ft_putendl("Lines are not well formated (different number of int).");
	return (0);
}

static int			check_size(char **file)
{
	int				max_size;
	int				size;
	int				i;
	int				j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		size = 0;
		while (file[i][++j])
			if (file[i][j] >= '0' && file[i][j] <= '9' &&
				(!j || file[i][j - 1] == ' ' || file[i][j - 1] == '-'))
				size++;
		if (!i)
			max_size = size;
		else if (size != max_size)
			return (put_file_error(4, '0'));
	}
	return (1);
}

int					check_file(char **file)
{
	int				valid;
	int				i;
	int				j;

	i = -1;
	valid = 0;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
			if ((file[i][j] < '0' || file[i][j] > '9') &&
				file[i][j] != ' ' && file[i][j] != '-')
				return (put_file_error(1, file[i][j]));
			else if (!valid)
				valid = 1;
	}
	if (!valid)
		return (put_file_error(3, '0'));
	return (check_size(file));
}
