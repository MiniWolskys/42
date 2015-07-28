/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:57:46 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 18:00:47 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*process(char const *s1, char c, size_t *index_start)
{
	char		*str;
	size_t		index;

	index = 0;
	while (s1[index + (*index_start)] && s1[index + (*index_start)] == c)
		index++;
	if (!(s1[index + (*index_start)]))
		return (NULL);
	*index_start += index;
	index = 0;
	while (s1[index + (*index_start)] && s1[index + (*index_start)] != c)
		index++;
	str = ft_strndup(&s1[*index_start], index);
	*index_start += index;
	return (str);
}

static size_t	ft_getsize_tab(char const *s1, char c)
{
	size_t		count;
	size_t		index;
	int			already;

	index = 0;
	count = 1;
	already = 1;
	while (s1[index])
	{
		if (s1[index] == c && !already)
		{
			already = 1;
			count++;
		}
		if (s1[index] != c && already)
			already = 0;
		index++;
	}
	return (count);
}

char			**ft_strsplit(char const *s1, char c)
{
	char		**tab;
	size_t		size_tab;
	size_t		index_glob;
	size_t		index;

	index = 0;
	index_glob = 0;
	if (!(s1) || !(c))
		return (NULL);
	size_tab = ft_getsize_tab(s1, c);
	tab = (char **)malloc(sizeof(*tab) * size_tab + 1);
	while (index <= size_tab)
	{
		tab[index] = process(s1, c, &index_glob);
		index++;
	}
	return (tab);
}
