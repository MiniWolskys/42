/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_slash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 02:40:19 by srison            #+#    #+#             */
/*   Updated: 2015/04/01 02:40:21 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				exec_slash(char *cmd, char **arg, char ***env)
{
	pid_t		father;

	if (!(father = fork()))
	{
		if ((open(cmd, O_RDONLY)) == -1)
			ft_putendl("No such file or directory.");
		else
		{
			execve(cmd, arg, *env);
			ft_putendl("Not an executable.");
		}
		exit(1);
	}
	wait(0);
	return (1);
}
