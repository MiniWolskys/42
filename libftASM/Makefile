# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srison <srison@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/06 21:35:22 by srison            #+#    #+#              #
#    Updated: 2015/05/06 21:35:23 by srison           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.exe

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
	ft_strcmp.s

SRCC = main.c

OBJ = $(SRCS:.s=.o) \
	$(SRCC:.c=.o)

CMPS = ~/.nasm/nasm -f macho64

CMPC = gcc -c

CMP = gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CMP)
	@echo "\033[0;31m######################################"
	@echo "#                                    #"
	@echo "#          ENDED COMPILATION         #"
	@echo "#                                    #"
	@echo "######################################\033[0m"

%.o: %.s
	@$(CMPS) -o $@ $^

%.o: %.c
	@$(CMPC) -o $@ $^

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
	@echo "\033[0;33m######################################"
	@echo "#                                    #"
	@echo "#         EXECUTABLE DELETED         #"
	@echo "#                                    #"
	@echo "######################################\033[0m"

re: fclean all
