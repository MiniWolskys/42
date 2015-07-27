/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 06:25:58 by srison            #+#    #+#             */
/*   Updated: 2015/05/09 06:25:59 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H

char			*ft_strcat(char *s1, char *s2);
char			*ft_strdup(char *str);

char			ft_isalnum(char c);
char			ft_isalpha(char c);
char			ft_isascii(char c);
char			ft_isdigit(char c);
char			ft_isprint(char c);
char			ft_tolower(char c);
char			ft_toupper(char c);
char			ft_islower(char c);
char			ft_isupper(char c);

int				ft_strlen(char *str);
int				ft_puts(char *str);
int				ft_strcmp(char *s1, char *s2);

void			*ft_memcpy(void *ptr1, void *ptr2, int n);
void			*ft_memset(void *ptr, int c, size_t n);

void			ft_bzero(void *ptr, size_t n);
void			ft_cat(int fd);

#endif
