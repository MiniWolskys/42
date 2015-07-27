/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 12:49:22 by srison            #+#    #+#             */
/*   Updated: 2015/04/01 03:38:44 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char			**cpy_env_smaller(char **env, int pos)
{
	char		**new_env;
	int			i;

	i = 0;
	while (env[i])
		i++;
	if (!(new_env = (char **)ft_memalloc(sizeof(env) * (i))))
		return (NULL);
	i = -1;
	while (env[++i])
	{
		if (i < pos)
			new_env[i] = ft_strdup(env[i]);
		else if (i > pos)
			new_env[i - 1] = ft_strdup(env[i]);
	}
	free_env(env);
	return (new_env);
}

char			**cpy_env_larger(char **env)
{
	int			i;
	char		**new_env;

	i = 0;
	while (env[i])
		i++;
	if (!(new_env = (char **)ft_memalloc(sizeof(env) * (i + 2))))
		return (NULL);
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	free_env(env);
	return (new_env);
}

static char		*get_path(char **env, char *shell)
{
	char		*path;
	int			i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			if (!(path = ft_strjoin("SHELL=", ft_strjoin(ft_strsub(env[i], 4,
				ft_strlen(env[i]) - 4),
				ft_strsub(shell, 1, ft_strlen(shell) - 1)))))
				return (NULL);
			return (path);
		}
		i++;
	}
	return (NULL);
}

static char		**null_env(void)
{
	char		**env;

	if (!(env = (char **)ft_memalloc(sizeof(*env) * 1)))
		return (NULL);
	*env = NULL;
	return (env);
}

char			**get_env(char **env, char *shell)
{
	int			i;
	int			path;
	char		**new_env;

	i = -1;
	path = 0;
	if (!(*env))
		return (null_env());
	while (env[++i])
		path = (!ft_strncmp(env[i], "PATH=", 5)) ? 1 : 0;
	if (!(new_env = (char **)ft_memalloc(sizeof(*new_env) * i +
		((!path) ? 2 : 1))))
		return (NULL);
	new_env[sizeof(*new_env) * i + 1] = NULL;
	while (i--)
		if (ft_strncmp(env[i], "SHELL=", 6))
		{
			if (!(new_env[i] = ft_strdup(env[i])))
				return (NULL);
		}
		else if (!(new_env[i] = get_path(env, shell)))
			return (NULL);
	new_env[i] = (!path) ? "PATH=" : new_env[i];
	return (new_env);
}
