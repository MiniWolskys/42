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

NAME = fractol

SRCS = srcs/main.c
SRCS += srcs/set_color.c
SRCS += srcs/img_pixel_put.c
SRCS += srcs/get_event.c
SRCS += srcs/julia.c
SRCS += srcs/mandel.c
SRCS += srcs/ship.c
SRCS += srcs/reset_image.c
SRCS += srcs/mouse_move.c

OBJ = $(SRCS:.c=.o)

HEADER = -Iincludes/ -Iincludes/libft/ -I./includes/minilibx_macos/

LIB = -L./includes/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit \
	-Lincludes/libft/ -lft \

GCC = gcc -Wall -Werror -Wextra -o $(NAME) $(HEADER) $(SRCS) $(LIB) \

all: $(NAME)

$(NAME): 
	@make -C ./includes/minilibx_macos/
	@make -C ./includes/libft/
	@$(GCC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

norme:
	norminette $(SRCS)
