# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 18:40:36 by srison            #+#    #+#              #
#    Updated: 2015/06/12 14:02:10 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c
SRC += ft_atof.c
SRC += ft_bzero.c
SRC += ft_isalnum.c
SRC += ft_strfill.c
SRC += ft_split_line.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_get_file.c
SRC += ft_islower.c
SRC += ft_isprint.c
SRC += ft_isupper.c
SRC += ft_lstnew.c
SRC += ft_itoa.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_lstiter.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_lstmap.c
SRC += ft_aatoai.c
SRC += ft_memdel.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_lstdelone.c
SRC += ft_putchar.c
SRC += ft_putendl.c
SRC += ft_putnbr.c
SRC += ft_lstdel.c
SRC += ft_putstr.c
SRC += ft_puttab.c
SRC += ft_strcat.c
SRC += ft_lstadd.c
SRC += ft_strchr.c
SRC += ft_strclr.c
SRC += ft_strcmp.c
SRC += ft_putstartl.c
SRC += ft_strcpy.c
SRC += ft_strdel.c
SRC += ft_strdup.c
SRC += ft_putnewl.c
SRC += ft_strndup.c
SRC += ft_strequ.c
SRC += ft_striter.c
SRC += ft_striteri.c
SRC += ft_strsplit.c
SRC += ft_strjoin.c
SRC += ft_strlen.c
SRC += ft_strmap.c
SRC += ft_strmapi.c
SRC += ft_strncat.c
SRC += ft_strncmp.c
SRC += ft_strshr.c
SRC += ft_strncpy.c
SRC += ft_strnequ.c
SRC += ft_strnew.c
SRC += ft_put_error.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c
SRC += ft_strstr.c
SRC += ft_set_color.c
SRC += ft_strsub.c
SRC += ft_strtrim.c
SRC += ft_tolower.c
SRC += ft_realloc.c
SRC += ft_toupper.c
SRC += ft_putchar_fd.c
SRC += ft_putstr_fd.c
SRC += ft_swap.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr_fd.c
SRC += ft_strlcat.c
SRC += ft_strdelchar.c
SRC += ft_square_root.c

POINTO = $(SRC:.c=.o)
	
FLAG = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(FLAG) -c $(SRC)
	@ar rc $(NAME) $(POINTO)
	@ranlib libft.a

compil: re clean

clean:
	@/bin/rm -f $(POINTO)
	@/bin/rm -f libft.h.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

norme: 
	norminette $(SRC)

list:
	@echo $(SRC)
