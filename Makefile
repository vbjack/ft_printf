# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 14:47:04 by andrey            #+#    #+#              #
#    Updated: 2021/01/16 19:06:13 by mtwitch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(HEADERS_DIR)
HEADERS_DIR = include
SOURCES_DIRS = src . proceccor
LIBFT_DIR = libft
HEADERS_LIST = $(wildcard *.h)
SOURCES_LIST = $(foreach dir, $(SOURCES_DIRS), $(SOURCES:$(dir)/%=%))s
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
SOURCES = $(foreach dir, $(SOURCES_DIRS), $(wildcard $(dir)/*.c))
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)	
	@cd $(LIBFT_DIR) && $(MAKE) re
	@echo "\033[1;32mlibftprintf: compile complite\033[0m"
	@ar rcs $(NAME) $(LIBFT_DIR)/objects/*o $(OBJECTS) && ranlib $(NAME)
	@echo "\033[1;32mlibftprintf: libftprintf.a created\033[0m\n"

$(SOURCES_DIR)%.o: $(SOURCES_DIR)%.c
	@gcc $(INCLUDE) -c $< -o $@

clean:
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@rm -rf *.o && rm -rf ./*/*.o
	@echo "\033[1;36mlibft: clean compile\033[0m"
	@echo "\033[1;32mlibftprintf: clean compile\033[0m\n"

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@rm -f $(NAME)
	@echo "\033[1;32mlibftprintf: fclean compile\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus
