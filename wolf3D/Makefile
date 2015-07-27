# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/02 01:33:00 by srison            #+#    #+#              #
#    Updated: 2015/07/02 01:33:02 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = srcs/main.c srcs/event.c srcs/boot.c srcs/calc.c srcs/draw.c srcs/set_pixel.c srcs/clear_mlx.c

OBJ = $(SRCS:.c=.o)

LIB = -L./includes/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit \
	-L./includes/libft/ -lft

INC = -I./includes/ -I./includes/minilibx_macos/ -I./includes/libft/

GCC = gcc -Wall -Werror -Wextra -o $(NAME) $(LIB) $(INC) $(SRC) \

all: $(NAME)

$(NAME):
	@make -s -C ./includes/minilibx_macos/
	@make -s -C ./includes/libft/
	@$(GCC)

clean:
	@rm -rf $(OBJ) 2>/dev/null || true

fclean: clean
	@rm $(NAME) 2>/dev/null || true

re: fclean all

norme:
	norminette $(SRCS)
