# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtwitch <mtwitch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 12:14:27 by mtwitch           #+#    #+#              #
#    Updated: 2021/01/16 19:06:26 by mtwitch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HEADER_DIR = ./
SOURCES_DIR = ./
OBJECTS_DIR = objects/
HEADERS_LIST = libft.h
SOURCES_LIST = ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c
OBJECTS_LIST = $(SOURCES:.c=.o)
BONUS_LIST = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c
OBJ_BONUSES = $(BONUS_LIST:.c=.o)
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))
BONUSES = $(addprefix $(OBJECTS_DIR), $(OBJ_BONUSES))

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS) bonus
	@echo "\033[1;36mlibft: compile complite\033[0m"
	@ar rc $(NAME) $(OBJECTS) && ranlib $(NAME)
	@echo "\033[1;36mlibft: libft.a created\033[0m\n"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c 
	@gcc $(FLAGS) -I $(HEADER_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;36mlibft: fclean compile\033[0m"

re: fclean all

bonus: $(OBJECTS_DIR) $(BONUSES)
	@ar rc $(NAME) $(BONUSES) && ranlib $(NAME)

.PHONY: all clean fclean re bonus
