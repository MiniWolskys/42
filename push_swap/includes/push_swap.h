/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:50:40 by srison            #+#    #+#             */
/*   Updated: 2015/02/05 13:50:41 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_struct		t_struct;

struct						s_struct
{
	int						pos;
	int						value;
	struct s_struct			*next;
};

void						push_swap(t_struct **a, t_struct **b);
void						push_b(t_struct **a, t_struct **b);
void						push_a(t_struct **a, t_struct **b);
void						swap_a(t_struct **a);
void						rota_a(t_struct **a);

#endif
