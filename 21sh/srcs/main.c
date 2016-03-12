/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:29:20 by srison            #+#    #+#             */
/*   Updated: 2016/03/12 18:26:11 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void		disp_sh(char **env)
{
	int			i;
	char		*path;

	i = 0;
	while (env[i] && ft_strcmp(env[i], "PWD") != '=')
		i++;
	path = ft_strstr(env[i], "srison");
	ft_putstr("[42sh] : ");
	ft_putstr(path);
	if (path)
		ft_putchar(' ');
	ft_putstr("> ");
}

int				main(int ac, char **av, char **env)
{
	char		**new_env;
//	char		**command_split;
	char		*command;
//	int			i;
	int			ret;

	if (!av || !ac || !(new_env = get_env(env, av[0])))
		return (1);
	ft_putstr("\033[H\033[2J");
	disp_sh(new_env);
	signal_handler();
	while (get_next_line(0, &command))
	{
		ret = read_command(command, &new_env);
/*
		command_split = ft_strsplit(command, ';');
		free(command);
		ret = 1;
		i = -1;
		while (command_split[++i])
			ret = exec_command(command_split[i], &new_env);
		free_env(command_split);
*/
		if (!ret)
			break ;
		disp_sh(new_env);
	}
	free_env(new_env);
	return (0);
}
