# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 18:40:36 by srison            #+#    #+#              #
#    Updated: 2016/03/12 18:25:48 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRCS = srcs/main.c srcs/get_env.c srcs/get_next_line.c srcs/exec_command.c \
	srcs/free.c srcs/execbuilt.c srcs/ft_cd.c srcs/signal_handler.c \
	srcs/exec_slash.c srcs/read_command.c \

OBJ = main.o get_env.o get_next_line.o exec_command.o free.o execbuilt.o \
	ft_cd.o signal_handler.o exec_slash.o \

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
