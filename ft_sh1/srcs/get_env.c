/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 12:49:22 by srison            #+#    #+#             */
/*   Updated: 2015/01/26 12:49:23 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		*get_path(char *path)
{
	
}

char			**get_env(char **env)
{
	int			i;
	char		**new_env;

	i = 0;
	while (env[i])
		i++;
	if (!(new_env = (char **)ft_memalloc(sizeof(*new_env) * i + 1)))
		return (NULL);
	new_env[sizeof(*new_env) * i + 1] = NULL;
	while (i--)
	{
		if (ft_strncmp(env, "PATH", 4))	
			new_env[i] = ft_putendl(env[i]);
		else
			new_env[i] = get_path(env[i]);
	}
	return (new_env);
}
