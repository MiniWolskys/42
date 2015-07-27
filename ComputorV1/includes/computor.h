/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:00:58 by srison            #+#    #+#             */
/*   Updated: 2015/06/13 18:31:29 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H

# define COMPUTOR_H

# define ABS(x) x < 0 ? -x : x

double			*get_equation(char *calc);
int				get_size(char *calc);
void			resolve(double *value, int max);
int				check_value(int max, double *value, int limit);

#endif
