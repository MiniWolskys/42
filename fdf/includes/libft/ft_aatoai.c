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

static void	get_line(int **line, char *file)
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
	free(tab);
	return ;
}

static int	*make_line(char *file)
{
	int		*line;
	size_t	size;
	int		i;

	i = -1;
	size = 1;
	while (file[++i])
		if (file[i] == ' ' && (file[i - 1] && file[i - 1] != ' '))
			size++;
	if (!(line = (int *)ft_memalloc(size + 1)))
		return (NULL);
	if (!file[0])
		line[0] = END_LINE;
	else
		line[size] = END_LINE;
	get_line(&line, file);
	return (line);
}

int			**ft_aatoai(char **src, int line_nb)
{
	int		**result;
	int		i;

	if (!src || line_nb < 1)
		return (NULL);
	if (!(result = (int **)ft_memalloc(sizeof(*result) * line_nb)))
		return (NULL);
	i = 0;
	while (i < line_nb)
	{
		if (!(result[i] = make_line(src[i])))
			return (NULL);
		i++;
	}
	return (result);
}
