/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:29:20 by srison            #+#    #+#             */
/*   Updated: 2015/03/19 11:27:40 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				main(int ac, char **av, char **env)
{
	char	**new_env;
	char	**command_split;
	char	*command;
	int		i;
	int		ret;

	if (!av || !ac || !(new_env = get_env(env, av[0])))
		return (1);
	ft_putstr("\033[H\033[J[ft_sh1] > ");
	signal_handler();
	while (get_next_line(0, &command))
	{
		command_split = ft_strsplit(command, ';');
		free(command);
		ret = 1;
		i = -1;
		while (command_split[++i])
			ret = exec_command(command_split[i], &new_env);
		free_env(command_split);
		if (!ret)
			break ;
		ft_putstr("[ft_sh1] > ");
	}
	free_env(new_env);
	return (0);
}
