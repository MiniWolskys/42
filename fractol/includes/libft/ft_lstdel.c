/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:10:11 by srison            #+#    #+#             */
/*   Updated: 2014/11/21 07:16:46 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*mem;

	mem = *alst;
	while ((*alst)->next)
	{
		ft_lstdelone(alst, del);
		*alst = (*alst)->next;
	}
	ft_lstdelone(&mem, del);
	return ;
}
