/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:29:20 by srison            #+#    #+#             */
/*   Updated: 2015/01/15 18:29:22 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			main(int ac, char **av, char **env)
{
	char	**new_env;
	char	*command;
	pid_t	father;

	if (!(new_env = get_env(env)))
		return (1);
	while (get_next_line(0, &command))
	{
		father = fork()
		if (!father)
			if (!(execve(command, NULL, env)))
				return (1);
		if (father > 0)
		{
			wait();
			ft_putstr("[ft_sh1]>");
		}
	}
	return (0);
}
