/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:53:53 by srison            #+#    #+#             */
/*   Updated: 2015/03/24 17:53:55 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int		cd_void(char ***env)
{
	char		*dir;
	int			i;

	i = 0;
	while ((*env)[i] && ft_strcmp((*env)[i], "HOME") != '=')
		i++;
	if (!(*env)[i])
	{
		ft_putendl("No home set.");
		return (0);
	}
	if (!(dir = ft_strdup(&((*env)[i][5]))))
		return (0);
	chdir(dir);
	free(dir);
	return (1);
}

static int		cd_prev(char ***env)
{
	int			i;
	char		*dir;

	i = 0;
	while ((*env)[i] && ft_strcmp((*env)[i], "OLDPWD") != '=')
		i++;
	if (!((*env)[i]))
	{
		ft_putendl("No OLDPWD set.");
		return (0);
	}
	if (!(dir = ft_strjoin("/", &((*env)[i][7]))))
		return (0);
	chdir(dir);
	free(dir);
	return (1);
}

static int		cmp(char *str)
{
	if (!ft_strcmp(str, "~") || !ft_strcmp(str, "-"))
		return (1);
	return (0);
}

int				ft_cd(char **arg, char ***env)
{
	char		*new_pwd;
	int			i;
	int			j;

	if (!(new_pwd = (char *)ft_memalloc(sizeof(*new_pwd) * 2048)) ||
		((!(arg[1]) || !ft_strcmp(arg[1], "~")) && !cd_void(env)) ||
		((arg[1]) && !ft_strcmp(arg[1], "-") && !cd_prev(env)))
		return (1);
	else if ((arg[1]) && !cmp(arg[1]) && (chdir(arg[1]) == -1))
		return (0);
	new_pwd = getcwd(new_pwd, 2048);
	i = -1;
	j = -1;
	while ((*env)[i] && ft_strcmp((*env)[i], "PWD") != '=')
		i++;
	while ((*env)[j] && ft_strcmp((*env)[j], "OLDPWD") != '=')
		j++;
	if (!(*env)[i] || !(env[j]))
		return (1);
	free((*env)[j]);
	(*env)[j] = ft_strjoin("OLDPWD=", &((*env)[i][5]));
	free((*env)[i]);
	(*env)[i] = ft_strjoin("PWD=", new_pwd);
	return (1);
}
