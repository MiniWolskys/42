/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aatoai.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:20:26 by srison            #+#    #+#             */
/*   Updated: 2015/01/14 13:20:28 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_line(int **line, char *file, t_pos *size)
{
	int		i;
	char	**tab;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!(tab = ft_strsplit(ft_strndup(file, i), ' ')))
		return ;
	i = 0;
	while (tab[i])
	{
		(*line)[i] = ft_atoi(tab[i]);
		i++;
	}
	while (i < size->x)
	{
		(*line)[i] = END_LINE;
		i++;
	}
	free(tab);
	return ;
}

static int	*make_line(char *file, t_pos *size)
{
	int		*line;

	if (!(line = (int *)ft_memalloc(sizeof(*line) * size->x + 1)))
		return (NULL);
	get_line(&line, file, size);
	return (line);
}

int			**ft_aatoai(char **src, t_pos *size)
{
	int		**result;
	int		i;

	if (!src || size->y < 1)
		return (NULL);
	if (!(result = (int **)ft_memalloc(sizeof(*result) * size->y)))
		return (NULL);
	i = 0;
	while (i < size->y)
	{
		if (!(result[i] = make_line(src[i], size)))
			return (NULL);
		i++;
	}
	return (result);
}
