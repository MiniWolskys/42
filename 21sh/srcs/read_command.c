/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:10:51 by srison            #+#    #+#             */
/*   Updated: 2016/03/12 18:26:03 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				read_command(char *cmd, char ***env)
{
	char		**splitted;
	int			ret;
	int			i;


	splitted = ft_strsplit(cmd, ';');
	ft_memdel((void **)&cmd);
	i = -1;
	while (splitted[++i])
		if ((ret = exec_command(splitted[i], env)) == -1)
			break ;
	free_env(splitted);
	return (ret);
}
