# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/31 22:13:10 by srison            #+#    #+#              #
#    Updated: 2015/06/13 14:52:05 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

SRCS = srcs/main.c \
	srcs/get_equation.c \
	srcs/get_size.c \
	srcs/resolve.c \

LIB = ./includes/libft/ -lft

INC = -I ./includes/ -I includes/libft/

GCC = clang -Wall -Werror -Wextra -o $(NAME) $(SRCS) -L $(LIB) $(INC)

all: $(NAME)

$(NAME):
	@make -s -C includes/libft/
	@$(GCC)
	@echo "\033[0;31m##############################"
	@echo "#                            #"
	@echo "#      COMPILATION DONE      #"
	@echo "#                            #"
	@echo "##############################\033[0;31m"

clean:
	@rm $(OBJ)
	@echo "\033[0;32m##############################"
	@echo "#                            #"
	@echo "#        OBJ DELETED         #"
	@echo "#                            #"
	@echo "##############################\033[0;32m"

fclean:
	@rm $(NAME)
	@echo "\033[0;33m##############################"
	@echo "#                            #"
	@echo "#        EXEC DELETED        #"
	@echo "#                            #"
	@echo "##############################\033[0;33m"

re: fclean all
