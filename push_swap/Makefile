# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/05 13:50:43 by srison            #+#    #+#              #
#    Updated: 2015/02/05 13:50:44 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/push_swap.c srcs/push.c srcs/swap.c srcs/rota.c \

OBJ = main.o push_swap.o push.o rota.o swap.o \

GCC = gcc -Wall -Werror -Wextra -o $(NAME) -I includes/ \
	  $(SRCS) -Llibft/ -lft

all: $(NAME)

$(NAME): 
	make -C libft/ re
	make -C libft/ clean
	$(GCC)
	
clean :
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

norme:
	norminette $(SRCS)

