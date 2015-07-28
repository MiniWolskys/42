/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 14:57:11 by srison            #+#    #+#             */
/*   Updated: 2014/12/23 19:19:41 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*put_null_error(int error)
{
	if (error == 0)
	{
		ft_putendl_fd("memory error", 2);
		ft_putendl_fd("     | FATAL ERROR |     ", 2);
	}
	if (error == 4)
	{
		ft_putendl_fd("Not enough arguments. Please mentions a file.", 2);
		ft_putendl_fd("     | FATAL ERROR |     ", 2);
	}
	return (NULL);
}

void		*ft_put_error(void *program_name, void *ptr, int error)
{
	if (program_name)
		ft_putstr_fd((char *)program_name, 2);
	else
		ft_putstr_fd("Program", 2);
	ft_putstr_fd(" error : ", 2);
	if (!ptr)
		return (put_null_error(error));
	ft_putstr_fd((char *)ptr, 2);
	if (error == 1)
		ft_putendl_fd(" : No such file or directory.", 2);
	if (error == 2)
		ft_putendl_fd(" : Permission denied", 2);
	if (error == 3)
	{
		ft_putendl_fd("illegat option", 2);
		ft_putstr_fd("usage : [-", 2);
		ft_putstr_fd(OPT_USAGE, 2);
		ft_putendl_fd("] [file ...]", 2);
	}
	return (NULL);
}
