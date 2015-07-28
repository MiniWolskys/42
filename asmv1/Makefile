# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/06 21:35:22 by srison            #+#    #+#              #
#    Updated: 2015/05/27 10:25:52 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.exe

LIB_NAME = libft.a

SRCS = ft_bzero.s \
	ft_cat.s \
	ft_isalnum.s \
	ft_isalpha.s \
	ft_isascii.s \
	ft_isdigit.s \
	ft_islower.s \
	ft_isprint.s \
	ft_isupper.s \
	ft_memcpy.s \
	ft_memset.s \
	ft_puts.s \
	ft_strcat.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_tolower.s \
	ft_toupper.s \
	ft_strcmp.s \
	ft_strchr.s \
	ft_swap.s \
	ft_strcut.s

SRCC = main.c

OBJ = $(SRCS:.s=.o)

CMPS = ~/.nasm/nasm -f macho64

CMP = gcc -Wall -Wextra -Werror -o $(NAME) $(SRCC) $(LIB_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(LIB_NAME) $(OBJ)
	@ranlib $(LIB_NAME)
	@$(CMP)
	@echo "\033[0;31m######################################"
	@echo "#                                    #"
	@echo "#          ENDED COMPILATION         #"
	@echo "#                                    #"
	@echo "######################################\033[0m"

%.o: %.s
	@$(CMPS) -o $@ $^

test: all
	./$(NAME)

clean:
	@rm $(OBJ)
	@echo "\033[0;32m######################################"
	@echo "#                                    #"
	@echo "#             OBJ DELETED            #"
	@echo "#                                    #"
	@echo "######################################\033[0m"

fclean: clean
	@rm $(NAME)
	@rm	$(LIB_NAME)
	@echo "\033[0;33m######################################"
	@echo "#                                    #"
	@echo "#         EXECUTABLE DELETED         #"
	@echo "#                                    #"
	@echo "######################################\033[0m"

re: fclean all
