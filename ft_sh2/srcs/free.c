/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:14:06 by srison            #+#    #+#             */
/*   Updated: 2015/03/21 15:14:07 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		free_line(char **arg, char *command)
{
	if (arg)
		free(arg);
	if (command)
		free(command);
	return ;
}

void		free_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}
