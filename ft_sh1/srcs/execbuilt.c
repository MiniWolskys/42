/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execbuilt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 03:09:21 by srison            #+#    #+#             */
/*   Updated: 2015/03/22 03:09:22 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void		ft_unsetenv(char **arg, char ***env)
{
	int			i;

	if (!arg[1] || arg[2])
	{
		ft_putendl("syntax error : use :\nunsetenv var");
		return ;
	}
	i = 0;
	while ((*env)[i] && ft_strcmp((*env)[i], arg[1]) != '=')
		i++;
	if (!(*env)[i])
	{
		ft_putendl("This variable cannot be found in the environment.");
		return ;
	}
	*env = cpy_env_smaller(*env, i);
}

static void		ft_setenv(char **arg, char ***env)
{
	int			i;
	char		*tmp;

	if (!arg[1] || !arg[2] || ft_strchr(arg[1], '=') || ft_strchr(arg[2], '='))
	{
		ft_putendl("syntax error : use :\nsetenv var value");
		return ;
	}
	i = 0;
	while ((*env)[i] && ft_strcmp((*env)[i], arg[1]) != '=')
		i++;
	if (!(*env)[i])
	{
		if (!(*env = cpy_env_larger(*env)))
			return ;
	}
	else
		free((*env)[i]);
	tmp = ft_strjoin(arg[1], "=");
	(*env)[i] = ft_strjoin(tmp, arg[2]);
	free(tmp);
	i = -1;
}

int				execbuilt(char *command, char **arg, char ***env)
{
	int		i;

	i = -1;
	if (!ft_strcmp(command, "exit"))
		return (0);
	else if (!ft_strcmp(command, "env") && !(arg[1]))
		while ((*env)[++i])
			ft_putendl((*env)[i]);
	else if (!ft_strcmp(command, "env") && (arg[1]))
		ft_putendl("syntax error : use :\nenv");
	else if (!ft_strcmp(command, "setenv"))
		ft_setenv(arg, env);
	else if (!ft_strcmp(command, "unsetenv"))
		ft_unsetenv(arg, env);
	else if (!ft_strcmp(command, "cd") && arg[1] && arg[2])
		ft_putendl("Too many arguments.");
	else if (!(ft_cd(arg, env)))
	{
		ft_putstr("cd error : it appears that you may not have the right to");
		ft_putendl(" do that, or that the file / directory may not exist.");
	}
	return (1);
}
