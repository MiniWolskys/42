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

static char			**split_char(char *str, int size)
{
	char			**result;
	int				size2;
	int				cnt;
	int				i;

	if (!(result = (char **)ft_memalloc(sizeof(*result) * (size + 1))))
		return (NULL);
	ft_bzero(result, size + 1);
	i = -1;
	cnt = 0;
	while (str[++i])
		if (((str[i] >= '0' && str[i] <= '9') || str[i] == '-') &&
			(!i || str[i - 1] == ' '))
		{
			size2 = 1;
			while (str[i + size2] && str[i + size2] != ' ')
				size2++;
			result[cnt] = ft_strndup(&(str[i]), size2);
			cnt++;
			i += size2;
		}
	return (result);
}

static int			*get_line(char *str)
{
	char			**value;
	int				*line;
	int				cnt;
	int				i;

	i = -1;
	cnt = 0;
	while (str[++i])
		if (((str[i] >= '0' && str[i] <= '9') || str[i] == '-') &&
			(!i || str[i - 1] == ' '))
			cnt++;
	if (!(line = (int *)ft_memalloc(sizeof(*line) * (cnt + 1))))
		return (NULL);
	line[cnt] = END_LINE;
	if (!(value = split_char(str, cnt)))
		free(line);
	if (!value)
		return (NULL);
	while (cnt--)
		line[cnt] = ft_atoi(value[cnt]);
	return (line);
}

int					**ft_aatoai(char **src)
{
	int				**result;
	int				x;

	x = 0;
	while (src[x])
		x++;
	x++;
	if (!(result = (int **)ft_memalloc(sizeof(*result) * (x + 1))))
		return (NULL);
	x = -1;
	while (src[++x])
		result[x] = NULL;
	result[x] = NULL;
	x = -1;
	while (src[++x])
		if (!(result[x] = get_line(src[x])))
		{
			while (x--)
				free(result[x]);
			free(result);
			return (NULL);
		}
	return (result);
}
