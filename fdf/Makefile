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

SRCS = srcs/main.c
SRCS += srcs/check_file.c
SRCS += srcs/mlx.c
SRCS += srcs/draw_calc.c

OBJ = $(SRCS:.c=.o)

HEADER = -Iincludes/ -Iincludes/libft/ -I./includes/minilibx_macos/

LIB = -L./includes/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit \
	-Lincludes/libft/ -lft \

GCC = gcc -Wall -Werror -Wextra -o $(NAME) $(HEADER) $(SRCS) $(LIB) \

all: $(NAME)

$(NAME): 
	@make -C ./includes/minilibx_macos/
	@make -C ./includes/libft/ re
	@make -C ./includes/libft/ clean
	@$(GCC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

norme:
	norminette $(SRCS)
