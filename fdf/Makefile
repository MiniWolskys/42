# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 20:11:25 by srison            #+#    #+#              #
#    Updated: 2014/12/22 10:00:57 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/main.c srcs/get_pos.c srcs/draw_line.c srcs/read_map.c \
		srcs/get_event.c srcs/get_map.c srcs/mlx_init.c \

OBJ = main.o get_pos.o draw_line.o read_map.o get_event.o get_map.o mlx_init.o \

GCC = gcc -Wall -Werror -Wextra -o $(NAME) -I includes/ \
	  $(SRCS) -Lincludes/libft/ -lft -L/usr/X11/lib -lX11 -lXext -lmlx

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
