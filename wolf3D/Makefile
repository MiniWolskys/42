# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/31 18:14:22 by srison            #+#    #+#              #
#    Updated: 2015/01/31 18:14:27 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D

SRCS = srcs/main.c srcs/load_map.c \

OBJ = main.o load_map.o \

GCC = gcc -Wall -Werror -Wextra -o $(NAME) -I includes/ \
	  $(SRCS) -Lincludes/libft/ -lft -L/usr/X11/lib -lX11 -lXext -lmlx

all: $(NAME)

$(NAME): 
	make -C includes/libft/ re
	make -C includes/libft/ clean
	$(GCC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

norme:
	norminette $(SRCS)

