/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:42:25 by srison            #+#    #+#             */
/*   Updated: 2015/06/17 07:45:06 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		*check_path(char *path, char *command)
{
	DIR			*dd;
	t_dir		*result;
	char		*ret;

	if (!(dd = opendir(path)))
		return (NULL);
	while ((result = readdir(dd)))
	{
		if (!ft_strcmp(result->d_name, command))
		{
			ret = ft_strjoin("/", command);
			free(command);
			command = ft_strjoin(path, ret);
			free(path);
			free(ret);
			closedir(dd);
			return (command);
		}
	}
	closedir(dd);
	return (NULL);
}

static char		*load_path(char *command, char *path_env)
{
	char		*path;
	int			end;
	int			mem;
	int			i;

	end = 0;
	i = 0;
	while (!end)
	{
		if (path_env[i] == '=')
			mem = i + 1;
		else if ((path_env[i] == ':' || !path_env[i]) && mem != i)
		{
			if ((path = check_path(ft_strndup(&(path_env[mem]), i - mem),
				command)))
				return (path);
			mem = i + 1;
		}
		if (!path_env[i])
			end = 1;
		i++;
	}
	return (NULL);
}

static int		load_builtin(char *command)
{
	if (!ft_strcmp(command, "env") || !ft_strcmp(command, "setenv") ||
		!ft_strcmp(command, "cd") || !ft_strcmp(command, "unsetenv") ||
		!ft_strcmp(command, "exit"))
		return (1);
	return (0);
}

static int		get_command(char *command, char **arg, char ***env, int i)
{
	char		*path;
	pid_t		father;

	path = NULL;
	if ((load_builtin(command)))
	{
		if (!(execbuilt(command, arg, env)))
			return (0);
	}
	else if (((*env)[i]) && (path = load_path(command, (*env)[i])))
	{
		if (!(father = fork()) && (execve(path, arg, *env)) == -1)
			ft_putendl("Not an executable.");
		wait(0);
	}
	else
	{
		ft_putstr(command);
		ft_putendl(" is not available as a command.");
	}
	if (path)
		free(path);
	return (1);
}

int				exec_command(char *line, char ***env)
{
	char	*command;
	char	**arg;
	int		i;

	if (!(arg = ft_strsplit(line, ' ')))
		return (0);
	if (!*arg)
		return (1);
	if (!(command = ft_strdup(arg[0])))
		return (0);
	i = -1;
	while ((*env)[++i])
		if (!ft_strncmp((*env)[i], "PATH=", 5))
			break ;
	if (ft_strchr(command, '/'))
		exec_slash(command, arg, env);
	else if (!get_command(command, arg, env, i))
		return (0);
	free(arg);
	return (1);
}
