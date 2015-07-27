/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:53:51 by srison            #+#    #+#             */
/*   Updated: 2015/03/30 18:53:53 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void		sigint_handler(int signo)
{
	signal(signo, SIG_IGN);
	ft_putstr("\b\b  \b\b");
	signal_handler();
}

void			signal_handler(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, sigint_handler);
}
