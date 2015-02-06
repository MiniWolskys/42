# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 18:40:36 by srison            #+#    #+#              #
#    Updated: 2014/12/02 17:58:36 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_sh1 

SRCS = srcs/main.c \

OBJ = main.o \

GCC = gcc -Wall -Werror -Wextra -o $(NAME) -I includes/ \
	  $(SRCS) -Lincludes/libft/ -lft

all: $(NAME)

$(NAME): 
	make -C includes/libft/ re
	make -C includes/libft/ clean
	$(GCC)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

norme:
	norminette $(SRCS)
