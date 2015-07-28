/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:29:35 by srison            #+#    #+#             */
/*   Updated: 2015/03/19 11:43:53 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H

# define FT_SH1_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct dirent	t_dir;

char					**get_env(char **env, char *shell);
int						exec_command(char *line, char ***env);
void					free_env(char **env);
void					free_line(char **arg, char *command);
int						execbuilt(char *command, char **arg, char ***env);
char					**cpy_env_larger(char **env);
char					**cpy_env_smaller(char **env, int pos);
int						ft_cd(char **arg, char ***env);
int						exec_slash(char *cmd, char **arg, char ***env);
void					signal_handler(void);

#endif
