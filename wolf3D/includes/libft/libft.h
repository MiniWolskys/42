/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srison <srison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:23:50 by srison            #+#    #+#             */
/*   Updated: 2015/06/12 14:00:18 by srison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define OPT_USAGE "none"
# define BUFF_SIZE 1024
# define END_LINE 483164
# define ABS(x) (x >= 0 ? x : -x)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_rgb
{
	char			blue;
	char			green;
	char			red;
	char			useless;
}					t_rgb;

typedef	struct		s_vec
{
	float			x;
	float			y;
}					t_vec;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int nb);
void				ft_putendl(char const *s);
void				ft_putnewl(char const *s);
void				ft_putstartl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_puttab(char **tab);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_strswap(char **s1, char **s2);
void				ft_swap(void **ptr1, void **ptr2);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
void				ft_lstadd(t_list **alst, t_list *new);

void				*ft_put_error(void *program_name, void *ptr, int error);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_realloc(void **p, size_t size, size_t new_size);

size_t				ft_strlen(char const *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_lstlen(void *lst);

float				ft_atof(char *str);
float				ft_square_root(float nbr, int prec);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(char *nbr);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_set_color(unsigned char red, unsigned char green,
						unsigned char blue);

char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strfill(char *str, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(char const *s1);
char				*ft_strndup(char const *s1, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strshr(char *str, char c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strdelchar(char const *str, char c);

int					**ft_aatoai(char **src);

char				**ft_split_line(char *src, char c);
char				**ft_get_file(int fd);
char				**ft_strsplit(char const *s1, char c);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
