/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:37:38 by srison            #+#    #+#             */
/*   Updated: 2015/03/19 10:17:14 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "libft/libft.h"
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int const fd, char **line);

#endif
