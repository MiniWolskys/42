/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:37:38 by srison            #+#    #+#             */
/*   Updated: 2014/11/13 19:29:33 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048

# include "libft.h"
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int const fd, char **line);

#endif
